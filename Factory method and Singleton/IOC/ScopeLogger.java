
package IOC;

import java.io.Closeable;
import java.io.IOException;

public class ScopeLogger implements Closeable
{
    private final ILogger iLogger;
    
    public ScopeLogger(ILogger iLogger)
    {
        this.iLogger = iLogger;
    }
    
    @Override
    public void close() throws IOException {
        iLogger.close();
    }
    
}
