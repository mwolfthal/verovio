package test.rismch.verovio.mei;

import org.junit.jupiter.api.Test;
import org.rismch.verovio.ToolkitInitializer;
import org.rismch.verovio.VrvRuntimeException;
import org.rismch.verovio.generated.Toolkit;
import org.rismch.verovio.logging.LogUtil;
import org.slf4j.Logger;

import java.nio.file.Files;
import java.nio.file.Paths;

import static org.junit.jupiter.api.Assertions.fail;


public class MeiTest
{
    private static final Logger logger;

    static
    {
        try
        {
            LogUtil.initLogger();
            logger = LogUtil.getLogger( MeiTest.class );
        }
        catch ( Exception e )
        {
            throw new VrvRuntimeException( e );
        }
    }

    @Test
    public void TestMei()
    {
        try
        {
            ToolkitInitializer.initialize();
            /*
             * create the toolkit and set the resource path
             * (if the fonts are installed (see the ./tools) then there is not need to do this)
             */
            Toolkit vrvToolkit = new Toolkit( false );
            vrvToolkit.setResourcePath( "../../data" );
            String options = "{'adjustPageHeight': true, 'breaks': 'auto', 'scale': 50}";
            /* set some options */
            vrvToolkit.setOptions( options );
            String mei = "";
            mei = new String( Files.readAllBytes(
                Paths.get( "../../doc/importer.mei" ) ) );
            /* load the data */
            vrvToolkit.loadData( mei );
            /* render the data to svg  and write it */
            String svg;
            svg = vrvToolkit.renderToSVG();
            String path = "output.svg";
            Files.write( Paths.get( path ), svg.getBytes() );
            logger.info( "wrote svg file {}", path );
        }
        catch ( Exception e )
        {
            logger.error( e.getMessage(), e );
            fail( e.getMessage() );
        }
    }
}

