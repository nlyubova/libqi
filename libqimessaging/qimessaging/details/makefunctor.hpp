/*
* AUTOGENERATED CODE, DO NOT EDIT
*
*  Author(s):
*  - Cedric GESTES <gestes@aldebaran-robotics.com>
*  - Chris  Kilner <ckilner@aldebaran-robotics.com>
*  Copyright (C) 2010, 2011, 2012 Aldebaran Robotics
*/

#pragma once
#ifndef _QIMESSAGING_DETAILS_MAKEFUNCTOR_HPP_
#define _QIMESSAGING_DETAILS_MAKEFUNCTOR_HPP_

#include <qimessaging/functor.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
namespace qi
{

  template <typename C, typename R>
  Functor *makeFunctor(C *obj, R (C::*f) ()) {
    return new detail::BoostFunctor<R ()>
      (boost::function<R ()>(
      boost::bind(f, obj )));
 }

  template <typename R>
  Functor *makeFunctor(R (*f) ()) {
    return new detail::BoostFunctor<R ()>
      (boost::function<R ()>(f));
 }


  template <typename P0, typename C, typename R>
  Functor *makeFunctor(C *obj, R (C::*f) (const P0 &p0)) {
    return new detail::BoostFunctor<R (const P0 &)>
      (boost::function<R (const P0 &)>(
      boost::bind(f, obj , _1)));
 }

  template <typename P0, typename R>
  Functor *makeFunctor(R (*f) (const P0 &p0)) {
    return new detail::BoostFunctor<R (const P0 &)>
      (boost::function<R (P0)>(f));
 }


  template <typename P0, typename P1, typename C, typename R>
  Functor *makeFunctor(C *obj, R (C::*f) (const P0 &p0, const P1 &p1)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &)>
      (boost::function<R (const P0 &, const P1 &)>(
      boost::bind(f, obj , _1, _2)));
 }

  template <typename P0, typename P1, typename R>
  Functor *makeFunctor(R (*f) (const P0 &p0, const P1 &p1)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &)>
      (boost::function<R (P0, P1)>(f));
 }


  template <typename P0, typename P1, typename P2, typename C, typename R>
  Functor *makeFunctor(C *obj, R (C::*f) (const P0 &p0, const P1 &p1, const P2 &p2)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &, const P2 &)>
      (boost::function<R (const P0 &, const P1 &, const P2 &)>(
      boost::bind(f, obj , _1, _2, _3)));
 }

  template <typename P0, typename P1, typename P2, typename R>
  Functor *makeFunctor(R (*f) (const P0 &p0, const P1 &p1, const P2 &p2)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &, const P2 &)>
      (boost::function<R (P0, P1, P2)>(f));
 }


  template <typename P0, typename P1, typename P2, typename P3, typename C, typename R>
  Functor *makeFunctor(C *obj, R (C::*f) (const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &, const P2 &, const P3 &)>
      (boost::function<R (const P0 &, const P1 &, const P2 &, const P3 &)>(
      boost::bind(f, obj , _1, _2, _3, _4)));
 }

  template <typename P0, typename P1, typename P2, typename P3, typename R>
  Functor *makeFunctor(R (*f) (const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &, const P2 &, const P3 &)>
      (boost::function<R (P0, P1, P2, P3)>(f));
 }


  template <typename P0, typename P1, typename P2, typename P3, typename P4, typename C, typename R>
  Functor *makeFunctor(C *obj, R (C::*f) (const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &, const P2 &, const P3 &, const P4 &)>
      (boost::function<R (const P0 &, const P1 &, const P2 &, const P3 &, const P4 &)>(
      boost::bind(f, obj , _1, _2, _3, _4, _5)));
 }

  template <typename P0, typename P1, typename P2, typename P3, typename P4, typename R>
  Functor *makeFunctor(R (*f) (const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &, const P2 &, const P3 &, const P4 &)>
      (boost::function<R (P0, P1, P2, P3, P4)>(f));
 }


  template <typename P0, typename P1, typename P2, typename P3, typename P4, typename P5, typename C, typename R>
  Functor *makeFunctor(C *obj, R (C::*f) (const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &, const P2 &, const P3 &, const P4 &, const P5 &)>
      (boost::function<R (const P0 &, const P1 &, const P2 &, const P3 &, const P4 &, const P5 &)>(
      boost::bind(f, obj , _1, _2, _3, _4, _5, _6)));
 }

  template <typename P0, typename P1, typename P2, typename P3, typename P4, typename P5, typename R>
  Functor *makeFunctor(R (*f) (const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &, const P2 &, const P3 &, const P4 &, const P5 &)>
      (boost::function<R (P0, P1, P2, P3, P4, P5)>(f));
 }


  template <typename P0, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename C, typename R>
  Functor *makeFunctor(C *obj, R (C::*f) (const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &, const P2 &, const P3 &, const P4 &, const P5 &, const P6 &)>
      (boost::function<R (const P0 &, const P1 &, const P2 &, const P3 &, const P4 &, const P5 &, const P6 &)>(
      boost::bind(f, obj , _1, _2, _3, _4, _5, _6, _7)));
 }

  template <typename P0, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename R>
  Functor *makeFunctor(R (*f) (const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &, const P2 &, const P3 &, const P4 &, const P5 &, const P6 &)>
      (boost::function<R (P0, P1, P2, P3, P4, P5, P6)>(f));
 }


  template <typename P0, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename C, typename R>
  Functor *makeFunctor(C *obj, R (C::*f) (const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &, const P2 &, const P3 &, const P4 &, const P5 &, const P6 &, const P7 &)>
      (boost::function<R (const P0 &, const P1 &, const P2 &, const P3 &, const P4 &, const P5 &, const P6 &, const P7 &)>(
      boost::bind(f, obj , _1, _2, _3, _4, _5, _6, _7, _8)));
 }

  template <typename P0, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename R>
  Functor *makeFunctor(R (*f) (const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &, const P2 &, const P3 &, const P4 &, const P5 &, const P6 &, const P7 &)>
      (boost::function<R (P0, P1, P2, P3, P4, P5, P6, P7)>(f));
 }


  template <typename P0, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename C, typename R>
  Functor *makeFunctor(C *obj, R (C::*f) (const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &, const P2 &, const P3 &, const P4 &, const P5 &, const P6 &, const P7 &, const P8 &)>
      (boost::function<R (const P0 &, const P1 &, const P2 &, const P3 &, const P4 &, const P5 &, const P6 &, const P7 &, const P8 &)>(
      boost::bind(f, obj , _1, _2, _3, _4, _5, _6, _7, _8, _9)));
 }

  template <typename P0, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename R>
  Functor *makeFunctor(R (*f) (const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)) {
    return new detail::BoostFunctor<R (const P0 &, const P1 &, const P2 &, const P3 &, const P4 &, const P5 &, const P6 &, const P7 &, const P8 &)>
      (boost::function<R (P0, P1, P2, P3, P4, P5, P6, P7, P8)>(f));
 }

  template<typename T>
  Functor* makeFunctor(boost::function<T> fun) {
    return new detail::BoostFunctor<T>(fun);
  }
}
#endif  // _QIMESSAGING_DETAILS_MAKEFUNCTOR_HPP_
