//
// Created by James Hunt on 4/4/19.
//

#include <jni.h>
#include <string>
#include <iostream>
#include "string"
#include "Store.hpp"

// auto store = std::make_unique<Store>();

extern "C" JNIEXPORT jlong JNICALL
Java_me_jameshunt_nativejni_KeyValueStore_jniInit(JNIEnv *env, jobject cls) {
    auto store = new Store();
    auto num = reinterpret_cast<jlong>(store);
    return num;
}

extern "C" JNIEXPORT jstring JNICALL
Java_me_jameshunt_nativejni_KeyValueStore_getJni(
        JNIEnv *env,
        jobject cls,
        jlong ptrLong,
        jstring jKey) {

    auto store = reinterpret_cast<Store *>(ptrLong);
    std::string key = env->GetStringUTFChars(jKey, nullptr);
    return env->NewStringUTF(store->getVal(key).data());
}

extern "C" JNIEXPORT void JNICALL
Java_me_jameshunt_nativejni_KeyValueStore_putJni(
        JNIEnv *env,
        jobject cls,
        jlong ptrLong,
        jstring key,
        jstring value) {

    std::string key1 = env->GetStringUTFChars(key, nullptr);
    std::string value1 = env->GetStringUTFChars(value, nullptr);
    auto store = reinterpret_cast<Store *>(ptrLong);
    store->putVal(key1, value1);
}

extern "C" JNIEXPORT void JNICALL
Java_me_jameshunt_nativejni_KeyValueStore_finishJni(
        JNIEnv *env,
        jobject cls,
        jlong ptrLong) {

    auto store = reinterpret_cast<Store *>(ptrLong);
    delete store;
}
