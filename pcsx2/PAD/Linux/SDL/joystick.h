/*  PCSX2 - PS2 Emulator for PCs
 *  Copyright (C) 2002-2020  PCSX2 Dev Team
 *
 *  PCSX2 is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU Lesser General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  PCSX2 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with PCSX2.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <SDL.h>
#include <SDL_haptic.h>

#include "../Global.h"
#include "../Device.h"

#define NB_EFFECT 2 // Don't use more than two, ps2 only has one for big motor and one for small(like most systems)

// holds all joystick info
class JoystickInfo : public Device
{
public:
	JoystickInfo(int id);
	~JoystickInfo();

	JoystickInfo(const JoystickInfo&) = delete;            // copy constructor
	JoystickInfo& operator=(const JoystickInfo&) = delete; // assignment


	// opens handles to all possible joysticks
	//static void EnumerateJoysticks(std::vector<std::unique_ptr<Device>>& vjoysticks);

	void Rumble(unsigned type, unsigned pad) override;
	void UpdateRumble(bool needs_update);

	bool TestForce(float) override;

	const char* GetName() final;

	int GetInput(gamePadValues input) final;

	void UpdateDeviceState() final;

	size_t GetUniqueIdentifier() final;

private:
	SDL_GameController* m_controller;
	u32 m_rumble_end[NB_EFFECT] = {};
	bool m_rumble_enabled[NB_EFFECT] = {};
	size_t m_unique_id;
	std::map<int, int> m_pad_to_sdl;
};

extern void EnumerateJoysticks(std::vector<std::unique_ptr<Device>>& vjoysticks);

// Values are hardcoded currently but it could be later extended to allow remapping of the buttons
static const std::map<int, int> default_sdl_button_map =
{
	{PAD_L2, SDL_CONTROLLER_AXIS_TRIGGERLEFT},
	{PAD_R2, SDL_CONTROLLER_AXIS_TRIGGERRIGHT},
	{PAD_L1, SDL_CONTROLLER_BUTTON_LEFTSHOULDER},
	{PAD_R1, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER},
	{PAD_TRIANGLE, SDL_CONTROLLER_BUTTON_Y},
	{PAD_CIRCLE, SDL_CONTROLLER_BUTTON_B},
	{PAD_CROSS, SDL_CONTROLLER_BUTTON_A},
	{PAD_SQUARE, SDL_CONTROLLER_BUTTON_X},
	{PAD_SELECT, SDL_CONTROLLER_BUTTON_BACK},
	{PAD_L3, SDL_CONTROLLER_BUTTON_LEFTSTICK},
	{PAD_R3, SDL_CONTROLLER_BUTTON_RIGHTSTICK},
	{PAD_START, SDL_CONTROLLER_BUTTON_START},
	{PAD_UP, SDL_CONTROLLER_BUTTON_DPAD_UP},
	{PAD_RIGHT, SDL_CONTROLLER_BUTTON_DPAD_RIGHT},
	{PAD_DOWN, SDL_CONTROLLER_BUTTON_DPAD_DOWN},
	{PAD_LEFT, SDL_CONTROLLER_BUTTON_DPAD_LEFT},
	{PAD_L_UP, SDL_CONTROLLER_AXIS_LEFTY},
	{PAD_L_RIGHT, SDL_CONTROLLER_AXIS_LEFTX},
	{PAD_L_DOWN, SDL_CONTROLLER_AXIS_LEFTY},
	{PAD_L_LEFT, SDL_CONTROLLER_AXIS_LEFTX},
	{PAD_R_UP,SDL_CONTROLLER_AXIS_RIGHTY},
	{PAD_R_RIGHT, SDL_CONTROLLER_AXIS_RIGHTX},
	{PAD_R_DOWN, SDL_CONTROLLER_AXIS_RIGHTY},
	{PAD_R_LEFT, SDL_CONTROLLER_AXIS_RIGHTX}
};

static const std::map<int, int> switch_sdl_button_map =
{
	{PAD_L2, SDL_CONTROLLER_AXIS_TRIGGERLEFT},
	{PAD_R2, SDL_CONTROLLER_AXIS_TRIGGERRIGHT},
	{PAD_L1, SDL_CONTROLLER_BUTTON_LEFTSHOULDER},
	{PAD_R1, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER},
	{PAD_TRIANGLE, SDL_CONTROLLER_BUTTON_X},
	{PAD_CIRCLE, SDL_CONTROLLER_BUTTON_A},
	{PAD_CROSS, SDL_CONTROLLER_BUTTON_B},
	{PAD_SQUARE, SDL_CONTROLLER_BUTTON_Y},
	{PAD_SELECT, SDL_CONTROLLER_BUTTON_BACK},
	{PAD_L3, SDL_CONTROLLER_BUTTON_LEFTSTICK},
	{PAD_R3, SDL_CONTROLLER_BUTTON_RIGHTSTICK},
	{PAD_START, SDL_CONTROLLER_BUTTON_START},
	{PAD_UP, SDL_CONTROLLER_BUTTON_DPAD_UP},
	{PAD_RIGHT, SDL_CONTROLLER_BUTTON_DPAD_RIGHT},
	{PAD_DOWN, SDL_CONTROLLER_BUTTON_DPAD_DOWN},
	{PAD_LEFT, SDL_CONTROLLER_BUTTON_DPAD_LEFT},
	{PAD_L_UP, SDL_CONTROLLER_AXIS_LEFTY},
	{PAD_L_RIGHT, SDL_CONTROLLER_AXIS_LEFTX},
	{PAD_L_DOWN, SDL_CONTROLLER_AXIS_LEFTY},
	{PAD_L_LEFT, SDL_CONTROLLER_AXIS_LEFTX},
	{PAD_R_UP,SDL_CONTROLLER_AXIS_RIGHTY},
	{PAD_R_RIGHT, SDL_CONTROLLER_AXIS_RIGHTX},
	{PAD_R_DOWN, SDL_CONTROLLER_AXIS_RIGHTY},
	{PAD_R_LEFT, SDL_CONTROLLER_AXIS_RIGHTX}
};
