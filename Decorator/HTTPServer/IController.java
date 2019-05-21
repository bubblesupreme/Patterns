
package HTTPServer;

import Response.HttpResponse;
import Request.HttpRequest;


public interface IController {
    
    public HttpResponse get(HttpRequest request);
    public HttpResponse post(HttpRequest request);
}
