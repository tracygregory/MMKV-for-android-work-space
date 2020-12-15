/*
 * Tencent is pleased to support the open source community by making
 * MMKV available.
 *
 * Copyright (C) 2020 THL A29 Limited, a Tencent company.
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

#ifdef __cplusplus
#    include <cstdint>
extern "C" {
#else
#    include <stdbool.h>
#    include <stdint.h>
#endif

struct GoStringWrap {
    const char *ptr;
    int64_t length;
};
typedef struct GoStringWrap GoStringWrap_t;

struct GoSliceWrap {
    void *array;
    int64_t length;
    int64_t capacity;
};
typedef struct GoSliceWrap GoSliceWrap_t;

void mmkvInitialize(GoStringWrap_t rootDir, int32_t logLevel);
void onExit();

void *getMMKVWithID(GoStringWrap_t mmapID, int32_t mode, GoStringWrap_t cryptKey, GoStringWrap_t rootPath);
void *getDefaultMMKV(int32_t mode, GoStringWrap_t cryptKey);
const char *mmapID(void *handle);

bool encodeBool(void *handle, GoStringWrap_t oKey, bool value);
bool decodeBool(void *handle, GoStringWrap_t oKey, bool defaultValue);

bool encodeInt32(void *handle, GoStringWrap_t oKey, int32_t value);
int32_t decodeInt32(void *handle, GoStringWrap_t oKey, int32_t defaultValue);

bool encodeUInt32(void *handle, GoStringWrap_t oKey, uint32_t value);
uint32_t decodeUInt32(void *handle, GoStringWrap_t oKey, uint32_t defaultValue);

bool encodeInt64(void *handle, GoStringWrap_t oKey, int64_t value);
int64_t decodeInt64(void *handle, GoStringWrap_t oKey, int64_t defaultValue);

bool encodeUInt64(void *handle, GoStringWrap_t oKey, uint64_t value);
uint64_t decodeUInt64(void *handle, GoStringWrap_t oKey, uint64_t defaultValue);

bool encodeFloat(void *handle, GoStringWrap_t oKey, float value);
float decodeFloat(void *handle, GoStringWrap_t oKey, float defaultValue);

bool encodeDouble(void *handle, GoStringWrap_t oKey, double value);
double decodeDouble(void *handle, GoStringWrap_t oKey, double defaultValue);

bool encodeBytes(void *handle, GoStringWrap_t oKey, GoStringWrap_t oValue);
void *decodeBytes(void *handle, GoStringWrap_t oKey, uint64_t *lengthPtr);

bool reKey(void *handle, GoStringWrap_t oKey);
void *cryptKey(void *handle, uint32_t *lengthPtr);
void checkReSetCryptKey(void *handle, GoStringWrap_t oKey);

GoStringWrap_t *allKeys(void *handle, uint64_t *lengthPtr);
bool containsKey(void *handle, GoStringWrap_t oKey);
uint64_t count(void *handle);
uint64_t totalSize(void *handle);
uint64_t actualSize(void *handle);

void removeValueForKey(void *handle, GoStringWrap_t oKey);
void removeValuesForKeys(void *handle, GoStringWrap_t *keyArray, uint64_t count);
void clearAll(void *handle);

void mmkvSync(void *handle, bool sync);
void clearMemoryCache(void *handle);
void trim(void *handle);
void mmkvClose(void *handle);

int32_t pageSize();
const char *version();

void setWantsLogRedirect(bool redirect);
void setWantsErrorHandle(bool errorHandle);
void setWantsContentChangeHandle(bool contentChange);

#ifdef __cplusplus
}
#endif
