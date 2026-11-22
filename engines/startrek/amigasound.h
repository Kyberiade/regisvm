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

#ifndef STARTREK_AMIGASOUND_H
#define STARTREK_AMIGASOUND_H

#include "common/str.h"

#include "audio/mixer.h"

#include "startrek/sound.h"

namespace StarTrek {

class StarTrekEngine;

// The Amiga version plays songs of "The Player 4.1A" and sampled sound effects
class AmigaSoundPlayer {
public:
	AmigaSoundPlayer(StarTrekEngine *vm);
	~AmigaSoundPlayer();

	void loadMusicFile(const Common::String &baseSoundName);
	void playTrack(int track, bool music);
	void stop(bool music, bool soundEffects);
	bool isMusicPlaying() const;
	bool isPlaying() const;
	int getMusicTrack() const { return _musicTrack; }

private:
	void playSong(int song);
	void playSoundEffect(int effect, Audio::SoundHandle *handle);

	StarTrekEngine *_vm;
	const int8 *_tracks;
	int _trackCount;
	int _musicTrack;
	Audio::SoundHandle _musicHandle;
	Audio::SoundHandle _sfxHandles[MAX_SFX_PLAYING];
	Common::String _bankName;
	byte *_bank;
	uint32 _bankSize;
};

} // End of namespace StarTrek

#endif
