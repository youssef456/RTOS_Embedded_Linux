[Unit]
Description=RTOS Application
After=network.target

[Service]
ExecStart=/usr/bin/rtos
Restart=on-failure

[Install]
WantedBy=default.target

