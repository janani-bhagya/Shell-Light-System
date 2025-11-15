#include <WiFi.h>
#include <WebServer.h>

#define LED_PIN1 2
#define LED_PIN2 4
#define LED_PIN3 12
#define LED_PIN4 13

const char* ssid = "Gimhani's Galaxy M02s";
const char* password = "12345678";

WebServer server(80);

bool system1State = false;
bool system2State = false;
bool system3State = false;
bool system4State = false;
bool system5State = false;
bool system6State = false;
bool system7State = false;
bool system8State = false;
bool system9State = false;
bool system10State = false;
bool system11State = false;
bool system12State = false;

unsigned long previousMillis_01 = 0;
unsigned long previousMillis_02 = 0;
unsigned long previousMillis_03 = 0;
unsigned long previousMillis_04 = 0;
unsigned long previousMillis_05 = 0;
unsigned long previousMillis_06 = 0;
unsigned long previousMillis_07 = 0;
unsigned long previousMillis_08 = 0;
unsigned long previousMillis_09 = 0;
unsigned long previousMillis_10 = 0;
unsigned long previousMillis_11 = 0;
unsigned long previousMillis_12 = 0;

const long interval_01 = 50;
const long interval_02 = 100;
const long interval_03 = 150;
const long interval_04 = 200;
const long interval_05 = 250;
const long interval_06 = 300;
const long interval_07 = 350;
const long interval_08 = 400;
const long interval_09 = 450;
const long interval_10 = 500;
const long interval_11 = 550;
const long interval_12 = 550;

bool isSystem01Active = false;
bool isSystem02Active = false;
bool isSystem03Active = false;
bool isSystem04Active = false;
bool isSystem05Active = false;
bool isSystem06Active = false;
bool isSystem07Active = false;
bool isSystem08Active = false;
bool isSystem09Active = false;
bool isSystem10Active = false;
bool isSystem11Active = false;
bool isSystem12Active = false;


IPAddress local_IP(192, 168, 9, 199);
IPAddress gateway(192, 168, 9, 1);
IPAddress subnet(255, 255, 255, 0);

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);

  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, HIGH);
  digitalWrite(LED_PIN3, HIGH);
  digitalWrite(LED_PIN4, HIGH);

  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi!");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/toggleSystem1", []() { toggleSystem(1); });
  server.on("/toggleSystem2", []() { toggleSystem(2); });
  server.on("/toggleSystem3", []() { toggleSystem(3); });
  server.on("/toggleSystem4", []() { toggleSystem(4); });
  server.on("/toggleSystem5", []() { toggleSystem(5); });
  server.on("/toggleSystem6", []() { toggleSystem(6); });
  server.on("/toggleSystem7", []() { toggleSystem(7); });
  server.on("/toggleSystem8", []() { toggleSystem(8); });
  server.on("/toggleSystem9", []() { toggleSystem(9); });
  server.on("/toggleSystem10", []() { toggleSystem(10); });
  server.on("/toggleSystem11", []() { toggleSystem(11); });
  server.on("/toggleSystem12", []() { toggleSystem(12); });

  server.begin();
}

void loop() {
  if (isSystem01Active) {
    System_01();
  }
  if (isSystem02Active) {
    System_02();
  }
  if (isSystem03Active) {
    System_03();
  }
  if (isSystem04Active) {
    System_04();
  }
  if (isSystem05Active) {
    System_05();
  }
  if (isSystem06Active) {
    System_06();
  }
  if (isSystem07Active) {
    System_07();
  }
  if (isSystem08Active) {
    System_08();
  }
  if (isSystem09Active) {
    System_09();
  }
  if (isSystem10Active) {
    System_10();
  }
  if (isSystem11Active) {
    System_11();
  }
  if (isSystem12Active) {
    System_12();
  }
  server.handleClient();
}

void toggleSystem(int system) {
  switch (system) {
    case 1:
      system1State = !system1State;
      Clear();
      if (system1State) {
        isSystem01Active = true;
      } else {
        isSystem01Active = false;
      }
      break;

    case 2:
      system2State = !system2State;
      Clear();
      if (system2State) {
        isSystem02Active = true;
      } else {
        isSystem02Active = false;
      }
      break;

    case 3:
      system3State = !system3State;
      Clear();
      if (system3State) {
        isSystem03Active = true;
      } else {
        isSystem03Active = false;
      }
      break;

    case 4:
      system4State = !system4State;
      Clear();
      if (system4State) {
        isSystem04Active = true;
      } else {
        isSystem04Active = false;
      }
      break;

      case 5:
      system5State = !system5State;
      Clear();
      if (system5State) {
        isSystem05Active = true;
      } else {
        isSystem05Active = false;
      }
      break;

      case 6:
      system6State = !system6State;
      Clear();
      if (system6State) {
        isSystem06Active = true;
      } else {
        isSystem06Active = false;
      }
      break;

      case 7:
      system7State = !system7State;
      Clear();
      if (system7State) {
        isSystem07Active = true;
      } else {
        isSystem07Active = false;
      }
      break;

      case 8:
      system8State = !system8State;
      Clear();
      if (system8State) {
        isSystem08Active = true;
      } else {
        isSystem08Active = false;
      }
      break;

      case 9:
      system9State = !system9State;
      Clear();
      if (system9State) {
        isSystem09Active = true;
      } else {
        isSystem09Active = false;
      }
      break;

      case 10:
      system10State = !system10State;
      Clear();
      if (system10State) {
        isSystem10Active = true;
      } else {
        isSystem10Active = false;
      }
      break;

      case 11:
      system11State = !system11State;
      Clear();
      if (system11State) {
        isSystem11Active = true;
      } else {
        isSystem11Active = false;
      }
      break;

      case 12:
      system12State = !system12State;
      Clear();
      if (system12State) {
        isSystem12Active = true;
      } else {
        isSystem12Active = false;
      }
      break;
  }
  server.send(200, "text/plain", "Toggled System " + String(system));
}

void handleRoot() {
  String html = "<!DOCTYPE html>";
  html += "<html lang='en'>";
  html += "<head>";
  html += "    <meta charset='UTF-8'>";
  html += "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>";
  html += "    <meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "    <title>LED Control Panel</title>";
  html += "    <link href='https://cdn.jsdelivr.net/npm/remixicon@4.3.0/fonts/remixicon.css' rel='stylesheet'>";
  html += "    <style>";
  html += "        :root {";
  html += "            --shadow: 0 3px 4px rgba(0, 0, 0, 1), inset 0 -2px 5px rgba(0, 0, 0, 1),";
  html += "                inset 0 2px 2px rgba(255, 255, 255, 0.5), 0 0 0 2px #000, 0 0 0 5px #0c0c0c,";
  html += "                0 0 0 5.5px #080808;";
  html += "            --shadow-color: yellow;";
  html += "        }";
  html += "        body {";
  html += "            margin: 0;";
  html += "            padding: 0;";
  html += "            display: flex;";
  html += "            justify-content: center;";
  html += "            align-items: center;";
  html += "            min-height: 100vh;";
  html += "            background: #111;";
  html += "        }";
  html += "        .card {";
  html += "            height: 550px;";
  html += "            width: 280px;";
  html += "            padding: 50px;";
  html += "            background: #1b1b1b;";
  html += "            border-radius: 8px;";
  html += "            justify-content: center;";
  html += "            box-shadow: var(--shadow);";
  html += "            display: flex;";
  html += "            flex-direction: column;";
  html += "            align-items: center;";
  html += "            justify-content: space-between;";
  html += "        }";
  html += "        .row {";
  html += "            width: 100%;";
  html += "            display: flex;";
  html += "            align-items: center;";
  html += "            justify-content: space-between;";
  html += "        }";
  html += "        .row h1{";
  html += "          font-family: Arial, Helvetica, sans-serif;";
  html += "          color: #878787;";
  html += "          text-align: center;";
  html += "          text-shadow: 0 0 60px #ffffff27, 0 0 80px #ffffff1d;";
  html += "        }";
  html += "        .btn {";
  html += "            width: 80px;";
  html += "            height: 80px;";
  html += "            background: #222;";
  html += "            border-radius: 50%;";
  html += "            box-shadow: var(--shadow);";
  html += "            cursor: pointer;";
  html += "            font-size: 30px;";
  html += "            color: #636363;";
  html += "            display: flex;";
  html += "            align-items: center;";
  html += "            justify-content: center;";
  html += "            border: none;";
  html += "        }";
  html += "        .btn:focus {";
  html += "            outline: none;";
  html += "        }";
  html += "        .active {";
  html += "            color: yellow;";
  html += "            box-shadow: 0 0 0 rgba(0, 0, 0, 1), inset 0 -2px 5px rgba(0, 0, 0, 1),";
  html += "                inset 0 5px 5px rgba(255, 255, 255, 0.1), 0 0 0 2px #000, 0 0 0 5px #0c0c0c,";
  html += "                0 0 0 7px yellow;";
  html += "            text-shadow: 0 0 15px yellow, 0 0 30px yellow;";
  html += "            animation: mymove 0.25s ease;";
  html += "        }";
  html += "    </style>";
  html += "</head>";
  html += "<body>";
  html += "    <div class='card'>";
  html += "        <div class='row'>";
  html += "            <h1>LED Control Panel</h1>";
  html += "        </div>";
  html += "        <div class='row'>";

  for (int i = 1; i <= 12; i++) {
    html += "            <button class='btn' onclick='toggleSystem(" + String(i) + ")'>";
    html += "                <i class='ri-lightbulb-line'></i>";
    html += "            </button>";
    if (i % 3 == 0) {
      html += "        </div><div class='row'>";
    }
  }

  html += "        </div>";
  html += "    </div>";
  html += "    <script>";
  html += "        function toggleSystem(systemId) {";
  html += "            const button = document.querySelectorAll('.btn')[systemId - 1];";
  html += "            button.classList.toggle('active');";
  html += "            console.log(`Toggled System ${systemId}`);";
  html += "            fetch(`/toggleSystem` + systemId).then(response => {";
  html += "                if (!response.ok) throw new Error('Network response was not ok');";
  html += "                return response.text();";
  html += "            }).then(data => console.log(data))";
  html += "            .catch(error => console.error('Error:', error));";
  html += "        }";
  html += "    </script>";
  html += "</body>";
  html += "</html>";

  server.send(200, "text/html", html);
}

void Clear() {
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN3, LOW);
  digitalWrite(LED_PIN4, LOW);
}

void System_01() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_01 >= interval_01) {
    previousMillis_01 = currentMillis;
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    digitalWrite(LED_PIN4, HIGH);
  }
}

void System_02() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_02 >= interval_02) {
    previousMillis_02 = currentMillis;
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    digitalWrite(LED_PIN4, HIGH);
    delay(50);
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    digitalWrite(LED_PIN4, LOW);
    delay(50);
  }
}

void System_03() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_03 >= interval_03) {
    previousMillis_03 = currentMillis;
    Clear();
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);

    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN4, HIGH);
    delay(100);
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN4, LOW);
    delay(100);
  }
}

void System_04() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_04 >= interval_04) {
    previousMillis_04 = currentMillis;
    Clear();
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN4, HIGH);

    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    delay(100);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    delay(100);
  }
}

void System_05() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_05 >= interval_05) {
    previousMillis_05 = currentMillis;
    Clear();
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN4, HIGH);
    delay(200);

    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN4, LOW);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    delay(200);
  }
}

void System_06() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_06 >= interval_06) {
    previousMillis_06 = currentMillis;
    Clear();
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    delay(100);
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN4, HIGH);
    delay(100);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    delay(100);
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN4, LOW);
    delay(100);
  }
}

void System_07() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_07 >= interval_07) {
    previousMillis_07 = currentMillis;
    Clear();
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);

    digitalWrite(LED_PIN1, HIGH);
    delay(200);
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN4, HIGH);
    delay(200);
    digitalWrite(LED_PIN4, LOW);
  }
}

void System_08() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_08 >= interval_08) {
    previousMillis_08 = currentMillis;
    Clear();
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN4, HIGH);

    digitalWrite(LED_PIN2, HIGH);
    delay(200);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, HIGH);
    delay(200);
    digitalWrite(LED_PIN3, LOW);
  }
}

void System_09() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_09 >= interval_09) {
    previousMillis_09 = currentMillis;
    Clear();
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    delay(200);

    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, HIGH);
    digitalWrite(LED_PIN4, HIGH);
    delay(200);
  }
}

void System_10() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_10 >= interval_10) {
    previousMillis_10 = currentMillis;
    Clear();
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    delay(200);

    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN3, LOW);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN4, HIGH);
    delay(200);
  }
}

void System_11() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_11 >= interval_11) {
    previousMillis_11 = currentMillis;
    Clear();
    digitalWrite(LED_PIN1, HIGH);
    delay(100);
    digitalWrite(LED_PIN1, LOW);
    delay(100);
    digitalWrite(LED_PIN2, HIGH);
    delay(100);
    digitalWrite(LED_PIN2, LOW);
    delay(100);
    digitalWrite(LED_PIN3, HIGH);
    delay(100);
    digitalWrite(LED_PIN3, LOW);
    delay(100);
    digitalWrite(LED_PIN4, HIGH);
    delay(100);
    digitalWrite(LED_PIN4, LOW);
    delay(100);
    digitalWrite(LED_PIN3, HIGH);
    delay(100);
    digitalWrite(LED_PIN3, LOW);
    delay(100);
    digitalWrite(LED_PIN2, HIGH);
    delay(100);
    digitalWrite(LED_PIN2, LOW);
    delay(100);
  }
}

void System_12() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_12 >= interval_12) {
    previousMillis_12 = currentMillis;
    Clear();
    digitalWrite(LED_PIN1, HIGH);
    delay(100);
    digitalWrite(LED_PIN2, HIGH);
    delay(100);
    digitalWrite(LED_PIN3, HIGH);
    delay(100);
    digitalWrite(LED_PIN4, HIGH);
    delay(100);
    digitalWrite(LED_PIN1, LOW);
    delay(100);
    digitalWrite(LED_PIN2, LOW);
    delay(100);
    digitalWrite(LED_PIN3, LOW);
    delay(100);
    digitalWrite(LED_PIN4, LOW);
    delay(100);

    digitalWrite(LED_PIN4, HIGH);
    delay(100);
    digitalWrite(LED_PIN3, HIGH);
    delay(100);
    digitalWrite(LED_PIN2, HIGH);
    delay(100);
    digitalWrite(LED_PIN1, HIGH);
    delay(100);
    digitalWrite(LED_PIN4, LOW);
    delay(100);
    digitalWrite(LED_PIN3, LOW);
    delay(100);
    digitalWrite(LED_PIN2, LOW);
    delay(100);
    digitalWrite(LED_PIN1, LOW);
    delay(100);
  }
}