package org.rismch.verovio;

import org.apache.commons.lang3.SystemUtils;
import org.rismch.verovio.utils.CommonUtil;

import java.io.File;

public final class Constants
{
    public static final String BACKSLASH_STR = "\\";
    public static final String COLON_STR = ":";
    public static final String EMPTY_STRING = "";
    public static final String EQUALS_STR = "=";
    public static final String FORWARD_SLASH_STR = "/";
    public static final String NEW_LINE_STR = "\n";

    public static final String SPACE_STR = " ";
    public static final String SPACE_URLENCODE = "%20";

    // System Properties for use in tests
    public static final String PN_VEROVIO_DATA_DIR = "VEROVIO_DATA_DIR";
    public static final String PN_VEROVIO_SO_DIR = "VEROVIO_SO_DIR";
    // Environment Variables for runtime

    public static final String CLASSPATH_PROTOCOL = "classpath";
}
