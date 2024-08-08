package org.rismch.verovio.test.pae;

import org.junit.jupiter.api.Test;
import org.rismch.verovio.ToolkitInitializer;
import org.rismch.verovio.VrvRuntimeException;
import org.rismch.verovio.generated.Toolkit;
import org.rismch.verovio.logging.LogUtil;
import org.slf4j.Logger;

import static org.junit.jupiter.api.Assertions.fail;

public class PaeTest
{
    private static final Logger logger;

    static
    {
        try
        {
            LogUtil.initLogger();
            logger = LogUtil.getLogger( PaeTest.class );
        }
        catch ( Exception e )
        {
            throw new VrvRuntimeException( e );
        }
    }

    @Test
    public void TestPae()
    {
        try
        {
            ToolkitInitializer.initialize();
            /*
             * Create the toolkit and set the resource path.
             * (If the fonts are installed (see ./tools) then
             * there is no need to do this.)
             */
            Toolkit vrvToolkit = new Toolkit( false );
            vrvToolkit.setResourcePath( "../../data" );

            String s;
            String out;

            s = "@start:00000400004625-1.1.1\n";
            s = s + "@clef:C-3\n";
            s = s + "@keysig:xFCG\n";
            s = s + "@key:\n";
            s = s + "@timesig:c\n";
            s = s + "@data:" + "'4CCDE" + "\n";
            s = s + "@end:00000400004625-1.1.1\n";

            /* set the format to PAE and load the data */
            vrvToolkit.setInputFrom( "pae" );
            vrvToolkit.loadData( s );

            /* convert it and write it to the standard output */
            out = vrvToolkit.renderToSVG();
            logger.info( out );
        }
        catch ( Exception e )
        {
            logger.error( e.getMessage() );
            fail( e.getMessage() );
        }
    }
}


