
package HTTPServer;

import Request.HttpRequest;
import Response.HttpResponse;
import Response.ResponseHeaders;
import Response.ResponseLine;
import java.io.ByteArrayInputStream;
import java.nio.charset.Charset;

public class FirstController implements IController{
    @Override
    public HttpResponse get(HttpRequest request)
    {
        ResponseHeaders headers=new ResponseHeaders();
        headers.addHeader("Server", "bubblesupreme-Server/2019-05-20");
        headers.addHeader("Content-Type", "text/html");
        headers.addHeader("Content-Length", "55");
        headers.addHeader("Connection", "close");
        return HttpResponse.OKResponse(headers,
                new ByteArrayInputStream("<html><body><h1>Hello from FirstController</h1></body></html>".getBytes(Charset.forName("UTF-8"))));
    }
    @Override
    public HttpResponse post(HttpRequest request)
    {
        ResponseLine res_line= new ResponseLine(request.getRequestLine().getVersion(),200, "OK");
        ResponseHeaders headers=new ResponseHeaders();
        headers.addHeader("Server", "bubblesupreme-Server/2019-05-20");
        headers.addHeader("Content-Type", "text/html");
        headers.addHeader("Content-Length", "55");
        headers.addHeader("Connection", "close");
        return new HttpResponse(res_line, headers,
                new ByteArrayInputStream("<html><body><h1>Hello from FirstController</h1></body></html>".getBytes(Charset.forName("UTF-8"))));
    }
}
