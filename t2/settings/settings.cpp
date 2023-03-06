#include "settings.h"
#include <json/json.hpp>
#include <fstream>

namespace t2 {
	namespace settings {
		float camera_move_speed_xy = 0.12;
		float camera_move_speed_z = 0.12;
		float camera_rotation_speed_pitch = 0.00075;
		float camera_rotation_speed_yaw = 0.00075;
		float camera_fov = 120;
		//bool set_camera = true;
		bool show_player_model = true;
		bool show_weapon_model = true;
		float third_person_zoom_rate = 0.1;

		void LoadSettings(void) {
			std::ifstream ifs("demo_settings.json");
			nlohmann::json settings_json = nlohmann::json::parse(ifs);
			nlohmann::json camera_json = settings_json["camera"];

			nlohmann::json camera_move_speed = camera_json["move_speed"];
			nlohmann::json camera_rotation_speed = camera_json["rotation_speed"];

			camera_move_speed_xy = camera_move_speed["xy"].get<float>();
			camera_move_speed_z = camera_move_speed["z"].get<float>();

			camera_rotation_speed_pitch = camera_rotation_speed["pitch"].get<float>();
			camera_rotation_speed_yaw = camera_rotation_speed["yaw"].get<float>();

			third_person_zoom_rate = camera_json["third_person_zoom_rate"].get<float>();

			camera_fov = camera_json["fov"].get<int>();

			show_player_model = camera_json["show_player_model"].get<bool>();
			show_weapon_model = camera_json["show_weapon_model"].get<bool>();



		}
	}
}