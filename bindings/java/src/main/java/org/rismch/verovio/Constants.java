package org.rismch.verovio;

import org.apache.commons.lang3.SystemUtils;

public final class Constants
{
    public static final String BACKSLASH_STR = "\\";
    public static final String COLON_STR = ":";
    public static final String EMPTY_STRING = "";
    public static final String EQUALS_STR = "=";
    public static final String FORWARD_SLASH_STR = "/";
    public static final String NEW_LINE_STR = "\n";
    public static final String JNI_LIBRARY_BASENAME = "VerovioJni";
    public static final String SPACE_STR = " ";
    public static final String SPACE_URLENCODE = "%20";
    public static final String UNIX_SHARED_LIBRARY_DOT_SUFFIX = ".so";
    public static final String WINDOWS_SHARED_LIBRARY_DOT_SUFFIX = ".dll";
    public static final String JNI_LIBRARY_NAME;

    static
    {
        if ( SystemUtils.IS_OS_WINDOWS )
        {
            JNI_LIBRARY_NAME = JNI_LIBRARY_BASENAME + WINDOWS_SHARED_LIBRARY_DOT_SUFFIX;
        }
        else
        {
            JNI_LIBRARY_NAME = JNI_LIBRARY_BASENAME + UNIX_SHARED_LIBRARY_DOT_SUFFIX;
        }
    }

    public static final String CLASSPATH_PROTOCOL = "classpath";
    // full path to the native library
    public static final String PN_VEROVIO_SO_PATH = "VEROVIO_SO_PATH";

}
