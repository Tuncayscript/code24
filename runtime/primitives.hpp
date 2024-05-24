/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This Code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this Code).
 *
 * Contact with ITGSS, 640 N McCarvy Blvd. , in the
 * city of Milpitas, zip Code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Sunday, May 24, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 


#pragma once

#include <__msvc_threads_core.hpp>
#include <cstdlib>
#include <type_traits>

#include <Windows.h>

namespace Concurrency {
    namespace details {
        class stl_condition_variable_win7 {
        public:
            stl_condition_variable_win7() = default;

            ~stl_condition_variable_win7()                                             = delete;
            stl_condition_variable_win7(const stl_condition_variable_win7&)            = delete;
            stl_condition_variable_win7& operator=(const stl_condition_variable_win7&) = delete;

            void wait(_Stl_critical_section* lock) {
                if (!wait_for(lock, INFINITE)) {
                    _CSTD abort();
                }
            }

            bool wait_for(_Stl_critical_section* lock, unsigned int timeout) {
                return SleepConditionVariableSRW(
                           &m_condition_variable, reinterpret_cast<PSRWLOCK>(&lock->_M_srw_lock), timeout, 0)
                    != 0;
            }

            void notify_one() {
                WakeConditionVariable(&m_condition_variable);
            }

            void notify_all() {
                WakeAllConditionVariable(&m_condition_variable);
            }

        private:
            void* unused                            = nullptr; // TRANSITION, ABI: was the vptr
            CONDITION_VARIABLE m_condition_variable = CONDITION_VARIABLE_INIT;
        };

        [[nodiscard]] inline stl_condition_variable_win7* _Get_cond_var(::_Cnd_internal_imp_t* _Cond) noexcept {
            return reinterpret_cast<stl_condition_variable_win7*>(&_Cond->_Cv_storage);
        }
    } // namespace details
} // namespace Concurrency
