package org.rismch.verovio.utils;

import org.jetbrains.annotations.NotNull;
import org.rismch.verovio.Constants;
import org.rismch.verovio.VrvException;

import java.io.File;
import java.lang.reflect.Array;
import java.util.Collection;
import java.util.Map;

public class CommonUtil
{
    public enum FileType
    {
        ANY,
        DIRECTORY,
        FILE
    }
    /**
     * check null or empty on Strings, Collections, Maps and arrays
     * and our Countable interface
     */
    public static boolean isNullOrEmpty( final Object o )
    {
        boolean isNullOrEmpty = true;
        if ( null != o )
        {
            if ( o instanceof String )
            {
                isNullOrEmpty = ( ( (String) o ).isEmpty() );
            }
            else if ( o instanceof Collection )
            {
                isNullOrEmpty = ( (Collection<?>) o ).isEmpty();
            }
            else if ( o instanceof Map<?, ?> )
            {
                isNullOrEmpty = ( (Map<?, ?>) o ).isEmpty();
            }
            // not "if instanceof Array"
            else if ( o.getClass().isArray() )
            {
                isNullOrEmpty = Array.getLength( o ) == 0;
            }
            else if ( o instanceof Countable )
            {
                isNullOrEmpty = ( (Countable) o ).isEmpty();
            }
            // If it is not any of the above at least we know
            // it is not null
            else
            {
                isNullOrEmpty = false;
            }
        }
        return isNullOrEmpty;
    }

    public static void notNull( Object o, String name ) throws VrvException
    {
        if ( null == o )
        {
            String msg = ( isNullOrEmpty( name ) ? "object" : name + " is null" );
            throw new VrvException( msg );
        }
    }
    /**
     * @param o Object to check
     * @param name for message
     * @throws VrvException if Object is null or empty
     */
    public static void notNullOrEmpty( final Object o, @NotNull String name )
        throws VrvException
    {
        if ( isNullOrEmpty( o ) )
        {
            String msg = ( isNullOrEmpty( name ) ? "object" : name + " is null or empty." );
            throw new VrvException( msg );
        }
    }
    /**
     * @param fileType
     *     - check for DIRECTORY or FILE if the file exists
     */
    private static String checkPath(
        @NotNull final String path,
        final boolean checkExists,
        final boolean checkRead,
        final boolean checkWrite,
        final FileType fileType ) // if ANY we don't check
        throws VrvException
    {
        if ( CommonUtil.isNullOrEmpty( path ) )
        {
            throw new VrvException( "path is null or empty" );
        }
        String canonicalPath;
        try
        {
            File f = new File( path );
            canonicalPath = f.getCanonicalPath();
            boolean exists = f.exists();
            boolean isReadable = f.canRead();
            boolean isWritable = f.canWrite();
            if ( checkExists && !exists )
            {
                throw new Exception( canonicalPath + " does not exist" );
            }
            if ( !exists )
            {
                if ( FileType.DIRECTORY == fileType )
                {
                    throw new Exception( canonicalPath +
                                         " is not a directory - nonexistent " );
                }
                else if ( FileType.FILE == fileType )
                {
                    throw new Exception( canonicalPath +
                                         " is not a regular file - nonexistent" );
                }
            }
            else
            {
                if ( FileType.DIRECTORY == fileType && !f.isDirectory() )
                {
                    throw new Exception( canonicalPath + " is not a directory " );
                }
                else if ( FileType.FILE == fileType && !f.isFile() )
                {
                    throw new Exception( canonicalPath + " is not a regular file" );
                }
            }
            if ( checkRead && !isReadable )
            {
                throw new VrvException( canonicalPath + " is not readable" );
            }
            if ( checkWrite && !isWritable )
            {
                throw new VrvException( canonicalPath + " is not readable" );
            }
        }
        catch ( Exception e )
        {
            throw new VrvException( e );
        }

        return canonicalPath;
    }
    public static String checkFileER( @NotNull final String path ) throws VrvException
    {
        return checkPath( path, true, true, false,
                          CommonUtil.FileType.FILE );
    }

    public static boolean hasWhitespace( final String s )
    {
        boolean result = false;
        if ( CommonUtil.isNullOrEmpty( s ) &&
             ( s.contains( " " ) ||
               s.contains( "\n" ) ||
               s.contains( "\r" ) ||
               s.contains( "\t" ) ) )
        {
            result = true;
        }
        return result;
    }

    private interface Countable
    {
        int size();

        boolean isEmpty();
    }

    public static String backToForward( @NotNull String s ) throws VrvException
    {
        CommonUtil.notNullOrEmpty( s, "string" );
        return( s.replace( Constants.BACKSLASH_STR,
            Constants.FORWARD_SLASH_STR ) );
    }
}
