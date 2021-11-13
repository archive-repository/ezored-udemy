package com.ezored.sample.app

import android.content.IntentFilter
import android.os.StrictMode
import android.util.Log
import androidx.appcompat.app.AppCompatDelegate
import androidx.lifecycle.ProcessLifecycleOwner
import androidx.multidex.MultiDexApplication
import com.dropbox.djinni.JNILoader
import com.ezored.core.ApplicationCore
import com.ezored.data.SharedData
import com.ezored.data.SharedDataPlatformServiceImpl
import com.ezored.io.FileHelper
import com.ezored.io.FileHelperPlatformServiceImpl
import com.ezored.net.http.HttpClient
import com.ezored.net.http.HttpClientPlatformServiceImpl
import com.ezored.sample.BuildConfig
import com.ezored.sample.data.AppData
import com.ezored.sample.observers.AppLifecycleObserver
import com.ezored.sample.receivers.ConnectivityChangeReceiver
import com.ezored.sample.utils.EnvironmentUtil
import com.ezored.util.Logger
import com.ezored.util.LoggerLevel
import com.ezored.util.LoggerPlatformServiceImpl

class Application : MultiDexApplication() {

    private var appData: AppData = AppData()

    override fun onCreate() {
        super.onCreate()

        instance = this

        initializeStrictMode()

        AppCompatDelegate.setCompatVectorFromResourcesEnabled(true)

        loadNativeLibrary()

        ProcessLifecycleOwner.get().lifecycle.addObserver(AppLifecycleObserver())

        registerReceivers()
    }

    private fun registerReceivers() {
        val intentFilter = IntentFilter()
        intentFilter.addAction("android.net.conn.CONNECTIVITY_CHANGE")

        registerReceiver(ConnectivityChangeReceiver(), intentFilter)
    }

    override fun onTerminate() {
        Logger.i("[Application : onTerminate] App terminated")
        super.onTerminate()
    }

    fun onMoveToForeground() {
        Logger.i("[Application : onMoveToForeground] App moved to foreground")
        appData.isAppInBackground = false
    }

    fun onMoveToBackground() {
        Logger.i("[Application : onMoveToBackground] App moved to background")
        appData.isAppInBackground = true
    }

    private fun loadNativeLibrary() {
        try {
            System.loadLibrary("Ezored")

            JNILoader.load()

            initializeLogger()
            initializeSharedData()
            initializeHttpClient()
            initializeFileHelper()
            initializeCore()
        } catch (e: UnsatisfiedLinkError) {
            Log.e(LOG_GROUP, "Could not load native library")
            e.printStackTrace()
        }
    }

    private fun initializeCore() {
        val initializationData = EnvironmentUtil.initializationData
        val deviceData = EnvironmentUtil.deviceData

        ApplicationCore.shared().initialize(initializationData, deviceData)
    }

    private fun initializeLogger() {
        Logger.shared().platformService = LoggerPlatformServiceImpl(LOG_GROUP)

        if (BuildConfig.DEBUG) {
            Logger.shared().setLevel(LoggerLevel.VERBOSE)
        } else {
            Logger.shared().setLevel(LoggerLevel.ERROR)
        }
    }

    private fun initializeSharedData() {
        SharedData.shared().platformService = SharedDataPlatformServiceImpl(applicationContext)
    }

    private fun initializeFileHelper() {
        FileHelper.shared().platformService = FileHelperPlatformServiceImpl()
    }

    private fun initializeHttpClient() {
        // http client (uncomment to use platform http client)
        HttpClient.shared().platformService = HttpClientPlatformServiceImpl()
    }

    private fun initializeStrictMode() {
        if (BuildConfig.DEBUG) {
            StrictMode.setThreadPolicy(
                StrictMode.ThreadPolicy.Builder()
                    .detectAll()
                    .penaltyLog()
                    .build()
            )

            StrictMode.setVmPolicy(
                StrictMode.VmPolicy.Builder()
                    .detectLeakedSqlLiteObjects()
                    .detectLeakedClosableObjects()
                    .penaltyLog()
                    .build()
            )
        }
    }

    companion object {
        private const val LOG_GROUP = "SAMPLE"

        lateinit var instance: Application
            private set
    }

}
