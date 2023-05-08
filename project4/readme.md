# Components
1.Alcohol Sensor<br>
2.NodeMCU<br>
3.USB Cable<br>
4.Jumper wires<br>
5.soilmoisture sensor

# Prereqisites
1.Arduino Software


# Outline
1.Generate Messages on Serial Monitor when Soil Sensor is Wet and dry, Alcohol Sensor is Normal and Drunken

# Libraries

1.ESP8266 configuration in arduino<br>

# connections
<table>
  <tr>
    <th>S.No</th>
    <th>soilmoisture sensor</th>
    <th>NodeMCU</th>
  </tr>
  <tr>
    <td>1</td>
    <td>VCC</td>
    <td>Vin</td>
  </tr>
  <tr>
    <td>2</td>
    <td>GND</td>
    <td>GND</td>
  </tr>
  <tr>
    <td>3</td>
    <td>D0</td>
    <td>D0</td>
  </tr>
  <br>
   <tr>
    <th>S.No</th>
    <th>alcohol sensor</th>
    <th>NodeMCU</th>
  </tr>
  <tr>
    <td>1</td>
    <td>VCC</td>
    <td>Vin</td>
  </tr>
  <tr>
    <td>2</td>
    <td>GND</td>
    <td>GND</td>
  </tr>
  <tr>
    <td>3</td>
    <td>A0</td>
    <td>A0</td>
  </tr>
  </table>
