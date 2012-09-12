#ifndef _QIMESSAGING_FUNCTIONTYPE_HXX_
#define _QIMESSAGING_FUNCTIONTYPE_HXX_

#include <boost/fusion/include/mpl.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/transform_view.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include <boost/function_types/function_type.hpp>
#include <boost/function_types/result_type.hpp>
#include <boost/function_types/parameter_types.hpp>
#include <boost/fusion/container/vector/convert.hpp>
#include <boost/fusion/include/as_vector.hpp>
#include <boost/fusion/include/as_list.hpp>
#include <boost/fusion/algorithm/transformation/transform.hpp>
#include <boost/fusion/include/transform.hpp>
#include <boost/fusion/functional/invocation/invoke_function_object.hpp>
#include <boost/fusion/container/generation/make_vector.hpp>
#include <boost/fusion/include/make_vector.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <boost/fusion/functional/adapter/unfused.hpp>
#include <boost/fusion/functional/generation/make_unfused.hpp>
#include <boost/fusion/functional/generation/make_fused.hpp>

namespace qi
{
  inline Type* FunctionType::resultType()
  {
    return _resultType;
  }

  inline const std::vector<Type*>& FunctionType::argumentsType()
  {
    return _argumentsType;
  }

  namespace detail
  {
    struct PtrToConstRef
    {
      // Drop the const, it prevents method calls from working
      template <typename Sig>
      struct result;

      template <class Self, typename T>
      struct result< Self(T) >
      {
        typedef typename boost::add_reference<
        //typename boost::add_const<
        typename boost::remove_pointer<
        typename boost::remove_reference<T>::type
        >::type
        //  >::type
        >::type type;
      };
      template<typename T>
      T& operator() (T* ptr) const
      {
        return *ptr;
      }
    };

    struct fill_arguments
    {
      inline fill_arguments(std::vector<Type*>* target)
      : target(target) {}

      template<typename T> void operator()(T*) const
      {
        target->push_back(typeOf<typename
          boost::remove_const<typename boost::remove_reference<T>::type>::type>());
      }
      std::vector<Type*>* target;
    };

    struct Transformer
    {
    public:
      inline Transformer(const std::vector<void*>* args)
      : args(args)
      , pos(0)
      {}
      template <typename Sig>
      struct result;

      template <class Self, typename T>
      struct result< Self(T) >
      {
        typedef T type;
      };
      template<typename T>
      void
      operator() (T* &v) const
      {
        v = (T*)(*args)[pos++];
      }
      const std::vector<void*> *args;
      mutable unsigned int pos;
    };

    template<typename SEQ, typename F> void* apply(SEQ sequence,
      F& function, const std::vector<void*> args)
    {
      ValueCopy res;
      boost::fusion::for_each(sequence, Transformer(&args));
      res, boost::fusion::invoke_function_object(function,
        boost::fusion::transform(sequence,
          PtrToConstRef()));
    return res.value;
    }
  } // namespace detail


  template<typename T> class FunctionTypeImpl:
  public virtual FunctionType,
  public virtual TypeImpl<boost::function<T> >
  {
  public:
    FunctionTypeImpl()
    {
      _resultType = typeOf<typename boost::function_types::result_type<T>::type >();
      typedef typename boost::function_types::parameter_types<T>::type ArgsType;
      boost::mpl::for_each<
        boost::mpl::transform_view<ArgsType,
        boost::add_pointer<
        boost::remove_const<
        boost::remove_reference<boost::mpl::_1> > > > >(detail::fill_arguments(&_argumentsType));
    }
    virtual void* call(void* func, const std::vector<void*>& args)
    {
      boost::function<T>* f = (boost::function<T>*)func;
      typedef typename boost::function_types::parameter_types<T>::type ArgsType;
      typedef typename  boost::mpl::transform_view<ArgsType,
      boost::remove_const<
      boost::remove_reference<boost::mpl::_1> > >::type BareArgsType;
      typedef typename boost::mpl::transform_view<BareArgsType,
      boost::add_pointer<boost::mpl::_1> >::type PtrArgsType;
      return detail::apply(boost::fusion::as_vector(PtrArgsType()), *f, args);
    }
  };

  template<typename T> FunctionType* makeFunctionType()
  {
    static FunctionTypeImpl<T> result;
    return &result;
  }

  template<typename T>
  FunctionValue makeFunctionValue(boost::function<T> f)
  {
    FunctionValue res;
    res.value = new boost::function<T>(f);
    res.type = makeFunctionType<T>();
    return res;
  }

  template<typename F> FunctionValue makeFunctionValue(F func)
  {
  return makeFunctionValue(boost::function<
    typename boost::remove_pointer<F>::type>(func));
  }

} // namespace qi
#endif
