/*
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2012 Aldebaran Robotics
*/

#include <qimessaging/future.hpp>
#include <boost/thread.hpp>

namespace qi {

  namespace detail {

    class FutureBasePrivate {
    public:
      FutureBasePrivate();
      boost::condition_variable _cond;
      boost::mutex              _mutex;
      std::string               _error;
      bool                      _isReady;
      bool                      _hasError;
    };

    FutureBasePrivate::FutureBasePrivate()
      : _cond(),
        _mutex(),
        _error(),
        _isReady(false),
        _hasError(false)
    {
    }

    FutureBase::FutureBase()
      : _p(new FutureBasePrivate())
    {
    }

    FutureBase::~FutureBase()
    {
      delete _p;
    };

    bool FutureBase::wait(int msecs) const {
      boost::mutex::scoped_lock lock(_p->_mutex);
      if (_p->_isReady || _p->_hasError)
        return true;
      if (msecs > 0)
        _p->_cond.timed_wait(lock, boost::posix_time::milliseconds(msecs));
      else
        _p->_cond.wait(lock);
      return _p->_isReady || _p->_hasError;
    }

    void FutureBase::reportReady() {
      boost::mutex::scoped_lock lock(_p->_mutex);
      _p->_isReady = true;
      _p->_cond.notify_all();
    }

    void FutureBase::reportError(const std::string &message) {
      boost::mutex::scoped_lock lock(_p->_mutex);
      _p->_hasError = true;
      _p->_isReady = true;
      _p->_error = message;
      _p->_cond.notify_all();
    }

    bool FutureBase::isReady() const {
      return _p->_isReady;
    }

    bool FutureBase::hasError() const {
      return _p->_hasError;
    }

    const std::string &FutureBase::error() const {
      wait();
      return _p->_error;
    }


    void FutureBase::reset() {
      boost::mutex::scoped_lock lock(_p->_mutex);
      _p->_isReady = false;
      _p->_error = std::string();
      _p->_hasError = false;
    }

  }

}

