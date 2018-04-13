/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef BuiltinConfig_hpp
#define BuiltinConfig_hpp

#include <WCDB/Config.hpp>
#include <WCDB/TimedQueue.hpp>

namespace WCDB {

class BuiltinConfig {
public:
    enum Order : int {
        Trace = 1,
        Cipher,
        Basic,
        Checkpoint,
        Tokenize,
    };

    static const Config basic;

    static const Config trace;
    static void SetGlobalPerformanceTrace(
        const Handle::PerformanceTraceCallback &globalTrace);
    static void SetGlobalSQLTrace(const Handle::SQLTraceCallback &globalTrace);

    static const Config
    cipherWithKey(const void *key, int keySize, int pageSize);

    static const Config checkpoint;

    static const Config tokenizeWithNames(const std::list<std::string> &names);

    static const Configs &defaultConfigs();

protected:
    static TimedQueue<std::string, const int> s_timedQueue;
    static std::shared_ptr<Handle::PerformanceTraceCallback>
        s_globalPerformanceTrace;
    static std::shared_ptr<Handle::SQLTraceCallback> s_globalSQLTrace;
};

} //namespace WCDB

#endif /* BuiltinConfig_hpp */