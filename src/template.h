#include <Arduino.h>

String htmlContent = R""(
      <html lang="en" data-bs-theme="dark">
        <head>
          <title>ESP32 Web Server</title>
          <link href="https://cdn.jsdelivr.net/npm/fastbootstrap@2.2.0/dist/css/fastbootstrap.min.css" rel="stylesheet" integrity="sha256-V6lu+OdYNKTKTsVFBuQsyIlDiRWiOmtC8VQ8Lzdm2i4=" crossorigin="anonymous">
        </head>
        <body>
          <div class="container mt-5">
            <div class="row">
              <div class="col-12 text-center">
                <h1>ESP32 Web Server</h1>
                <p>Car control</p>
              </div>
            </div>
            <div id="alert">

            </div>
          </div>
         
          <script>
           
          </script>
          <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-C6RzsynM9kWDrMNeT87bh95OGNyZPhcTNXj1NW7RuBCsyN/o0jlpcV8Qyq46cDfL" crossorigin="anonymous"></script>
        </body>
      </html>
    )"";