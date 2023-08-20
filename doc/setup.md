
# How to setup PawnScript?

Let's assume you've got an empty open.mp/SA:MP server ready to use. You can get one [here](https://github.com/openmultiplayer/open.mp/releases).

<img height="300" align="center" src="https://cdn.discordapp.com/attachments/1130879376423145522/1142888793645535343/image.png">

Create `scriptfiles` and `gamemodes` folders.

<img height="300" align="center" src="https://cdn.discordapp.com/attachments/1130879376423145522/1142889338523357264/image.png">

Go to the releases page and select the latest release.

<img height="400" align="center" src="//https://cdn.discordapp.com/attachments/1130879376423145522/1142896097212248214/image.png">

Download the `pawnscript` archive that suits your OS; `.zip` for Microsoft Windows and `.tar.gz` for Linux. Open the archive and extract `pawnscript.amx` into your `gamemodes` folder.


<img height="400" align="center" src="https://cdn.discordapp.com/attachments/1130879376423145522/1142896842737197087/image.png">

Open `config.json` in an editor of your choice and paste this code (just change `main_scripts` to `pawnscript` and change your RCON password):

```json
{
    "announce": true,
    "artwork": {
        "cdn": "",
        "enable": true,
        "models_path": "models"
    },
    "chat_input_filter": true,
    "enable_query": true,
    "game": {
        "allow_interior_weapons": true,
        "chat_radius": 200.0,
        "death_drop_amount": 0,
        "gravity": 0.008,
        "group_player_objects": false,
        "lag_compensation_mode": 1,
        "map": "",
        "mode": "",
        "nametag_draw_radius": 70.0,
        "player_marker_draw_radius": 250.0,
        "player_marker_mode": 1,
        "time": 12,
        "use_all_animations": false,
        "use_chat_radius": false,
        "use_entry_exit_markers": true,
        "use_instagib": false,
        "use_manual_engine_and_lights": false,
        "use_nametag_los": true,
        "use_nametags": true,
        "use_player_marker_draw_radius": false,
        "use_player_ped_anims": false,
        "use_stunt_bonuses": true,
        "use_vehicle_friendly_fire": false,
        "use_zone_names": false,
        "vehicle_respawn_time": 10000,
        "weather": 10
    },
    "language": "",
    "logging": {
        "enable": true,
        "log_chat": true,
        "log_cookies": false,
        "log_deaths": true,
        "log_queries": false,
        "log_sqlite": false,
        "log_sqlite_queries": false,
        "timestamp_format": "[%Y-%m-%dT%H:%M:%S%z]",
        "use_prefix": true,
        "use_timestamp": true
    },
    "max_bots": 0,
    "max_players": 50,
    "name": "open.mp server",
    "network": {
        "acks_limit": 3000,
        "aiming_sync_rate": 30,
        "allow_037_clients": true,
        "bind": "",
        "cookie_reseed_time": 300000,
        "in_vehicle_sync_rate": 30,
        "limits_ban_time": 60000,
        "message_hole_limit": 3000,
        "messages_limit": 500,
        "minimum_connection_time": 0,
        "mtu": 576,
        "multiplier": 10,
        "on_foot_sync_rate": 30,
        "player_marker_sync_rate": 2500,
        "player_timeout": 10000,
        "port": 7777,
        "public_addr": "",
        "stream_radius": 200.0,
        "stream_rate": 1000,
        "time_sync_rate": 30000,
        "use_lan_mode": false
    },
    "password": "",
    "pawn": {
        "legacy_plugins": [],
        "main_scripts": [
            "pawnscript"
        ],
        "side_scripts": []
    },
    "rcon": {
        "allow_teleport": false,
        "enable": false,
        "password": "123"
    },
    "sleep": 5.0,
    "use_dyn_ticks": true,
    "website": "open.mp"
}
```

If you are using a SA:MP server, then you just need to change the `gamemodes` to `pawnscript` and change your RCON password.

Now, open your `scriptfiles` folder and create 2 files; `index.ps` (PawnScript code entry) and `config.psproj` (project settings).

<img height="400" align="center" src="https://cdn.discordapp.com/attachments/1130879376423145522/1142898851519410216/image.png">

Afterwards, open `config.psproj` in an editor of your choice and paste this:

```ini
project_name=My PawnScript Project
stack_output=true
```

And then, lastly, open your `index.ps` and start writing code!

<img height="100" align="center" src="https://cdn.discordapp.com/attachments/1130879376423145522/1142899985675989073/image.png">

Then run your server.

<img height="400" align="center" src="https://cdn.discordapp.com/attachments/1130879376423145522/1142901174417231953/image.png">

And that's it!