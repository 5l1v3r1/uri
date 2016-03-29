#if !defined(BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)

#ifndef BOOST_PHOENIX_CORE_DETAIL_FUNCTION_EVAL_HPP
#define BOOST_PHOENIX_CORE_DETAIL_FUNCTION_EVAL_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/phoenix/core/call.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/core/detail/phx2_result.hpp>
#include <boost/utility/result_of.hpp>

#include <boost/phoenix/core/detail/preprocessed/function_eval.hpp>

#endif
#else

#if !BOOST_PHOENIX_IS_ITERATING

#ifndef BOOST_PHOENIX_CORE_DETAIL_FUNCTION_EVAL_HPP
#define BOOST_PHOENIX_CORE_DETAIL_FUNCTION_EVAL_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/phoenix/core/call.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/core/detail/phx2_result.hpp>
#include <boost/utility/result_of.hpp>

#if defined(__WAVE__) && defined(BOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/function_eval_" BOOST_PHOENIX_LIMIT_STR ".hpp")
#endif
/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/


#if defined(__WAVE__) && defined(BOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

BOOST_PHOENIX_DEFINE_EXPRESSION_VARARG(
    (network_boost)(network_boostphoenix)(detail)(function_eval)
  , (meta_grammar)
    (meta_grammar)
  , BOOST_PP_DEC(BOOST_PHOENIX_COMPOSITE_LIMIT)
)

namespace network_boost { namespace network_boostphoenix {
    namespace detail
    {
        template <typename T>
        T& help_rvalue_deduction(T& x)
        {
            return x;
        }
        
        template <typename T>
        T const& help_rvalue_deduction(T const& x)
        {
            return x;
        }

        struct function_eval
        {
            template <typename Sig>
            struct result;

            template <typename This, typename F, typename Context>
            struct result<This(F, Context)>
            {
                typedef typename
                    remove_reference<
                        typename network_boost::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;

                typedef typename network_boost::result_of<fn()>::type type;
            };

            template <typename F, typename Context>
            typename result<function_eval(F const&, Context const&)>::type
            operator()(F const & f, Context const & ctx) const
            {
                return network_boost::network_boostphoenix::eval(f, ctx)();
            }

            template <typename F, typename Context>
            typename result<function_eval(F &, Context const&)>::type
            operator()(F & f, Context const & ctx) const
            {
                return network_boost::network_boostphoenix::eval(f, ctx)();
            }

        #define PHOENIX_GET_ARG(z, n, data)                                     \
            typedef                                                             \
                typename network_boost::add_reference<                                  \
                    typename network_boost::add_const<                                  \
                        typename network_boost::result_of<                              \
                            network_boost::network_boostphoenix::evaluator(                          \
                                BOOST_PP_CAT(A, n)                              \
                              , Context                                         \
                            )                                                   \
                        >::type                                                 \
                    >::type                                                     \
                >::type                                                         \
                BOOST_PP_CAT(a, n);

        #define PHOENIX_EVAL_ARG(z, n, data)                                    \
            help_rvalue_deduction(network_boost::network_boostphoenix::eval(BOOST_PP_CAT(a, n), ctx))
        
        #define M0(z, n, data)                                     \
            typename proto::detail::uncvref<BOOST_PP_CAT(a, n)>::type

        #define BOOST_PHOENIX_ITERATION_PARAMS                                  \
            (3, (1, BOOST_PP_DEC(BOOST_PHOENIX_ACTOR_LIMIT),                    \
            <boost/phoenix/core/detail/function_eval.hpp>))
#include BOOST_PHOENIX_ITERATE()

        #undef PHOENIX_GET_ARG
        #undef PHOENIX_EVAL_ARG
        #undef M0
        
        };
        
    }

    template <typename Dummy>
    struct default_actions::when<detail::rule::function_eval, Dummy>
        : network_boostphoenix::call<detail::function_eval>
    {};
}}

#if defined(__WAVE__) && defined(BOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif


#endif

#else
            template <
                typename This
              , typename F
              , BOOST_PHOENIX_typename_A
              , typename Context
            >
            struct result<This(F, BOOST_PHOENIX_A, Context)>
            {
                typedef typename
                    remove_reference<
                        typename network_boost::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;

                BOOST_PP_REPEAT(BOOST_PHOENIX_ITERATION, PHOENIX_GET_ARG, _)

                typedef typename
                    network_boost::result_of<fn(BOOST_PHOENIX_a)>::type
                    type;
                /*
                typedef typename
                    mpl::eval_if_c<
                        has_phx2_result<
                            fn
                          , BOOST_PP_ENUM(BOOST_PHOENIX_ITERATION, M0, _)
                        >::value
                      , network_boost::result_of<
                            fn(
                                BOOST_PHOENIX_a
                            )
                        >
                      , phx2_result<
                            fn
                          , BOOST_PHOENIX_a
                        >
                    >::type
                    type;
                */
            };

            template <typename F, BOOST_PHOENIX_typename_A, typename Context>
            typename result<
                function_eval(
                    F const &
                  , BOOST_PHOENIX_A_ref
                  , Context const &
                )
            >::type
            operator()(F const & f, BOOST_PHOENIX_A_ref_a, Context const & ctx) const
            {
                return network_boost::network_boostphoenix::eval(f, ctx)(BOOST_PP_ENUM(BOOST_PHOENIX_ITERATION, PHOENIX_EVAL_ARG, _));
            }

            template <typename F, BOOST_PHOENIX_typename_A, typename Context>
            typename result<
                function_eval(
                    F &
                  , BOOST_PHOENIX_A_ref
                  , Context const &
                )
            >::type
            operator()(F & f, BOOST_PHOENIX_A_ref_a, Context const & ctx) const
            {
                return network_boost::network_boostphoenix::eval(f, ctx)(BOOST_PP_ENUM(BOOST_PHOENIX_ITERATION, PHOENIX_EVAL_ARG, _));
            }
#endif

#endif
