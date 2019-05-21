
package HTTPServer;

import Request.HttpRequest;
import Response.HttpResponse;
import java.util.logging.Logger;

public class LoggingControllerWrapper implements IController{
    private IController simple_controller;
    private Logger log;
    
    public LoggingControllerWrapper(IController simple_controller)
    {
        this.simple_controller=simple_controller;
        log=Logger.getLogger(LoggingControllerWrapper.class.getName());
    }
            
    @Override
    public HttpResponse get(HttpRequest request)
    {
        log.info("GET method was called");
        return simple_controller.get(request);
    }
    @Override
    public HttpResponse post(HttpRequest request)
    {
        log.info("POST method was called");
        return simple_controller.post(request);
    }
}
