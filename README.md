# MQTT Library für den HPI-Schülerklub

Diese Bibliothek dient dazu, Teilnehmenden bei HPI-Schülerklub-Camps den Einstieg in die Kommunikation mit WLAN-Netzwerken und MQTT zu vereinfachen.

Dazu stellt die Bibliothek einen einfachen Weg bereit, sich mit einem gegebenen WLAN-Netzwerk und MQTT-Server zu verbinden.

## Beispielcode

Ein Beispiel kann in der Datei `examples/example.cpp` gefunden werden. Wichtig ist vorallem das richtige Setzen der Zugangsdaten.
Die callback-Funktion erhält das Thema und den Inhalt einer empfangenen Nachricht für alle Themen, die abonniert wurden.

## Einbinden der Bibliothek

Um diese Bibliothek zu nutzen, muss dieses Repo auf einer öffentlichen Git-Instanz liegen. Dann kann einfach die URL des Git-Repos in der `platformio.ini` hinzugefügt werden. Die Ressourcen werden dann automatisch heruntergeladen und genutzt.