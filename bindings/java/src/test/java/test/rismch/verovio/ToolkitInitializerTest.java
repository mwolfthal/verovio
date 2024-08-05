package test.rismch.verovio;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestInfo;
import org.rismch.verovio.Constants;
import org.rismch.verovio.ToolkitInitializer;
import org.rismch.verovio.VrvException;

import static org.junit.jupiter.api.Assertions.*;

public class ToolkitInitializerTest
{
    @Test
    public void testValid( TestInfo testInfo )
    {
        try
        {
            ToolkitInitializer.initialize();
        }
        catch ( Exception e )
        {
            fail( testInfo.getDisplayName() + " got unexpected exception: " +
                  e.getMessage() );
        }
        System.out.println( testInfo.getDisplayName() + " succeeded " );
    }

    @Test
    public void testWithInvalidPath( TestInfo testInfo )
    {
        Exception e = assertThrows( VrvException.class, () ->
        {
            ToolkitInitializer.initialize( "foo.dll" );
        } );
        System.out.println( testInfo.getDisplayName() +
                            " got expected exception: " + e.getMessage() );
    }

    @Test
    public void testWithNullSystemProperty( TestInfo testInfo )
    {
        System.setProperty( Constants.PN_VEROVIO_SO_DIR, "" );
        Exception e = assertThrows( VrvException.class, () ->
        {
            ToolkitInitializer.initialize( "foo.dll" );
        } );
        System.out.println( testInfo.getDisplayName() + " got expected exception: " +
                            e.getMessage() );
    }
}
