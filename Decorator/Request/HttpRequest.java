
package Request;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.text.ParseException;
import java.util.Map;

public class HttpRequest {
    private RequestLine reqLine;
    private RequestHeaders reqHeaders;
    private RequestBody reqBody;
    public HttpRequest(BufferedReader request) throws IOException, ParseException
    {
        reqLine= new RequestLine(request.readLine());
        reqHeaders = new RequestHeaders();
        while(true) {
                String headerLine= request.readLine();
                if(headerLine == null || headerLine.trim().length() == 0) {
                    break;
                }
                else
                {
                    reqHeaders.addHeader(headerLine);
                }
            }
        if (checkMessage())
        {
            reqBody = new RequestBody(new ByteArrayInputStream(request.readLine().getBytes()));
        }
        else
        {
            reqBody = new RequestBody();
        }
    }
    
    private boolean checkMessage()
    {
        for (Map.Entry<String, String> reqHeader : 
                reqHeaders.getHeaders().entrySet())
        {
            if (reqHeader.getKey().equals("Content-Length") 
                    && reqHeader.getValue().equals("0"))
            {
                return true;
            }
        };
        return false;
    }
    
    public RequestLine getRequestLine()
    {
        return reqLine;
    }
    
    public RequestHeaders getRequestHeaders()
    {
        return reqHeaders;
    }
    
    public RequestBody getRequestBody()
    {
        return reqBody;
    }
}
