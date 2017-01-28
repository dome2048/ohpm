# ohpm
**OpenHab Particle Monitor**
============================

Designed to run on Particle's Photon-based Internet Button, the OpenHab Particle Monitor provides a link between you and your OpenHab-connected house, even when you're away from home. The OHPM exposes three OpenHab switches (Alarm, Trouble, and Light) which you can add to groups or automate through rules. As long as the Internet Button is powered, connected to a WiFi network, and configured properly, you'll receive an alert if there's an issue at home. Unlike solutions like MQTT, the OHPM intentionally uses the Particle Cloud to pass updates to your device whenever it has an internet connection.

The setup also has a "timeout" feature, such that if the Internet Button hasn't heard a "status OK" message from OpenHab for a few mintues, the system will alert you. If you rely on a smartphone to receive alerts from your house, this provides a way to leave your phone on silent with the assurance you'll be notified of an issue.

This setup was designed for and tested on OpenHab2. It might work with modification on OpenHab 1; but, since OH2 is out of beta and stable, I'd recommend just getting it updated (after a good backup). There's lots of guidance for this on the OpenHab community forums.


### **ALERT TYPES** ###
* Alarm On: Flashing red and blue with an audible tone. Meant for intrusion/burglar alarms.
* Trouble On: Spinning yellow light with a periodic "chirp." Ideal for water sensors or HVAC failure.
* Light On: All LEDs light up white. If you're the nervous type, this can assure you that lighting schedules are running properly.
* Disconnected: Alternating blue and yellow spinning lights with a periodic chirp indicate the OHPM isn't receiving updates from OpenHab.
* Note: Alarm and Trouble supersede the Light. If both Alarm and Trouble are activated, you'll see red and blue flashes mixed with a spinning yellow light to indicate both problems.

### **INSTALLATION** ###

* Get a Particle Internet Button if you don't have one: <https://store.particle.io/products/internet-button>

* Getting the Particle device ready:
	* Clone this repository to your desktop.
	* Make sure your internet button has a Photon (Spark might work, not tested) installed, is powered on, and is connected to WiFi.
	* Copy contents of "ohpm.cpp" into a new sketch on the Particle Build IDE (<https://build.particle.io/build>), and flash the code to your device.
	* On the left, click on the Devices tab. Click on the device you're using, then copy the "Device ID." You'll need it later.

* Setting OpenHab up to communicate with the OHPM:
	* Navigate to your OpenHab web address, click on PaperUI, then Addons, then Bindings. Navigate to the Garadget binding and click Install. (If you prefer, feel free to install the binding through addons.cfg as well.)
	* Still in the PaperUI, click on Configuration on the left, Bindings, then under the Garadget binding, click on "Configure". Enter your Particle Build username (email) and password. Hit save. You're now done with the PaperUI and can close it.
	* Access your OpenHab configuration folder via whatever route you prefer (SMB with Eclipse SmartHome editor is my preferred method), you'll need to make several changes here.
	* Place "ohpm.items" into your OpenHab Items folder.
	* Open "ohpm.items" in your editor of choice. Change "PARTICLEDEVICEID" to the value you copied earlier. Save and close.
	* Place "ohpm.rules" into your OpenHab Rules folder.
	* Place "ohpm.sitemap" into your OpenHab Sitemaps folder. This step is optional but allows you to quickly test whether everything is working.

* Test it out at: <http://youropenhabserver:8080/basicui/app?sitemap=ohpm>

### **NEXT STEPS** ###

If you have issues, I suggest checking the OpenHab logs first.

Integrate the exposed switches in your rules or by adding them to appropriate groups in the sitemap. If this is beyond your comfort zone, consider some reading at <http://docs.openhab.org> and <https://community.openhab.org>.

Thanks to John Cocula (<https://github.com/watou>) for his work on the Garadget Binding, and for everyone who has contributed to making OpenHab2 a successful reality.
