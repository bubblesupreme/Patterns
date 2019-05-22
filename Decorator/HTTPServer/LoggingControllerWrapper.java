
package HTTPServer;

import Request.HttpRequest;
import Response.HttpResponse;
import java.util.logging.Logger;

public class LoggingControllerWrapper implements IController{
    private IController baseController;
    private Logger log;
    
    public LoggingControllerWrapper(IController baseController)
    {
        this.baseController=baseController;
        log=Logger.getLogger(LoggingControllerWrapper.class.getName());
    }
            
    @Override
    public HttpResponse get(HttpRequest request)
    {
        log.info("GET method was called");
        return baseController.get(request);
    }
    @Override
    public HttpResponse post(HttpRequest request)
    {
        log.info("POST method was called");
        return baseController.post(request);
    }
}
