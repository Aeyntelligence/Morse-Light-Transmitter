using UnityEngine;
using UnityEngine.UI;
using System.IO.Ports;

public class moresender : MonoBehaviour
{
    SerialPort port = new SerialPort("COM3", 9600);
    public InputField inputField;
    public Text statusText;

    void Start()
    {
        port.Open();
        port.ReadTimeout = 100;
        statusText.text = "Connected to Arduino.";
    }

    public void SendMorse()
    {
        string msg = inputField.text;
        port.WriteLine(msg);
        statusText.text = "Message sent: " + msg;
    }

    void OnApplicationQuit()
    {
        if (port.IsOpen)
            port.Close();
    }
}
