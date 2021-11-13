// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

package com.ezored.dataservices;

import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicBoolean;

public abstract class TodoDataService {
    public static void truncate()
    {
        CppProxy.truncate();
    }

    public static com.ezored.domain.Todo findById(long id)
    {
        return CppProxy.findById(id);
    }

    public static ArrayList<com.ezored.domain.Todo> findAllOrderByCreatedAtDesc()
    {
        return CppProxy.findAllOrderByCreatedAtDesc();
    }

    public static ArrayList<com.ezored.domain.Todo> findByTitle(String title)
    {
        return CppProxy.findByTitle(title);
    }

    public static void removeById(long id)
    {
        CppProxy.removeById(id);
    }

    public static void update(long id, com.ezored.domain.Todo todo)
    {
        CppProxy.update(id,
                        todo);
    }

    public static long insert(com.ezored.domain.Todo todo)
    {
        return CppProxy.insert(todo);
    }

    public static long add(com.ezored.domain.Todo todo)
    {
        return CppProxy.add(todo);
    }

    public static void setDoneById(long id, boolean done)
    {
        CppProxy.setDoneById(id,
                             done);
    }

    private static final class CppProxy extends TodoDataService
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void _djinni_private_destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            _djinni_private_destroy();
            super.finalize();
        }

        public static native void truncate();

        public static native com.ezored.domain.Todo findById(long id);

        public static native ArrayList<com.ezored.domain.Todo> findAllOrderByCreatedAtDesc();

        public static native ArrayList<com.ezored.domain.Todo> findByTitle(String title);

        public static native void removeById(long id);

        public static native void update(long id, com.ezored.domain.Todo todo);

        public static native long insert(com.ezored.domain.Todo todo);

        public static native long add(com.ezored.domain.Todo todo);

        public static native void setDoneById(long id, boolean done);
    }
}