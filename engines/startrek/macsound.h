/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef STARTREK_MACSOUND_H
#define STARTREK_MACSOUND_H

#include "common/str.h"
#include "common/scummsys.h"

namespace Audio {
class HalestormDriver;
}

namespace StarTrek {

class MacSoundLoader;
class StarTrekEngine;

// The Mac versions play the songs and sound effects of "Star Trek Audio"
class MacSoundPlayer {
public:
	MacSoundPlayer(StarTrekEngine *vm);
	~MacSoundPlayer();

	bool init();
	void syncSoundSettings();
	void loadMusicFile(const Common::String &baseSoundName);
	void playTrack(int track, bool music);
	void stop(bool music, bool soundEffects);
	bool isMusicPlaying() const;
	int getMusicTrack() const { return _musicTrack; }

private:
	StarTrekEngine *_vm;
	MacSoundLoader *_loader;
	Audio::HalestormDriver *_driver;
	const int16 *_tracks;
	int _trackCount;
	int _musicTrack;
};

} // End of namespace StarTrek

#endif
