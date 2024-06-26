#include <Arduino.h>

String htmlContent = R""(
      <!DOCTYPE html>
<html lang="en" data-bs-theme="dark">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>ESP32 Web Server</title>
  <link href="https://cdn.jsdelivr.net/npm/fastbootstrap@2.2.0/dist/css/fastbootstrap.min.css" rel="stylesheet" integrity="sha256-V6lu+OdYNKTKTsVFBuQsyIlDiRWiOmtC8VQ8Lzdm2i4=" crossorigin="anonymous">
</head>
<body>
  <div class="container mt-5">
    <div class="row">
      <div class="col-12 text-center">
        <h1>ESP32 Web Server</h1>
        <p>Car Control</p>
      </div>
    </div>
    <div class="row">
        <div class="col-6 row mx-auto">
            <div class="col-12 text-center mb-3">
                <button class="btn btn-primary" onclick="sendCommand('/forward')">Forward</button>
            </div>
            <div class="col-6 text-end mb-3">
                <button class="btn btn-secondary" onclick="sendCommand('/turnLeft')">Turn Left</button>
            </div>
            <div class="col-6 text-start mb-3">
                <button class="btn btn-secondary" onclick="sendCommand('/turnRight')">Turn Right</button>
            </div>
            <div class="col-12 text-center mb-3">
                <button class="btn btn-danger" onclick="sendCommand('/backward')">Backward</button>
            </div>
        </div>
        <div class="col-6 row mx-auto">
            
            <div class="col-12 text-center mb-3">
                <button class="btn btn-warning" onclick="sendCommand('/stop')">Stop</button>
            </div>
            <div class="col-12 text-center mb-3">
                <button class="btn btn-info" onclick="sendCommand('/buzzer')">Buzzer</button>
            </div>

        </div>
    </div>
    <div id="alert" class="text-center">

    </div>
  </div>

  <script>
    function sendCommand(command) {
      fetch(command)
        .then(response => {
          if (response.ok) {
            showAlert('Command sent: ' + command, 'success');
          } else {
            showAlert('Error sending command: ' + command, 'danger');
          }
        })
        .catch(error => {
          showAlert('Network error: ' + error.message, 'danger');
        });
    }

    function showAlert(message, type) {
      const alertDiv = document.getElementById('alert');
      alertDiv.innerHTML = `<div class="alert alert-${type}" role="alert">${message}</div>`;
      setTimeout(() => alertDiv.innerHTML = '', 3000);
    }
  </script>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-C6RzsynM9kWDrMNeT87bh95OGNyZPhcTNXj1NW7RuBCsyN/o0jlpcV8Qyq46cDfL" crossorigin="anonymous"></script>
</body>
</html>
    )"";