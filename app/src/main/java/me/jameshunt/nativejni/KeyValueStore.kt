package me.jameshunt.nativejni

class KeyValueStore : AutoCloseable {

    private var ptr: Long = 0

    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }

    init {
        ptr = jniInit()
    }

    fun put(key: String, value: String) {
        putJni(ptr = ptr, key = key, value = value)
    }

    fun get(key: String): String {
        return getJni(ptr = ptr, key = key)
    }

    protected fun finalize() {
        close()
    }

    override fun close() {
        println("close me plz")
        finishJni(ptr)
    }

    private external fun jniInit(): Long
    private external fun getJni(ptr: Long, key: String): String
    private external fun putJni(ptr: Long, key: String, value: String)
    private external fun finishJni(ptr: Long)
}