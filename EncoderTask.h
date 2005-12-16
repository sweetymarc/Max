/*
 *  $Id: EncoderTask.h 184 2005-11-30 05:39:33Z me $
 *
 *  Copyright (C) 2005 Stephen F. Booth <me@sbooth.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#import <Cocoa/Cocoa.h>

#import "Encoder.h"
#import "Track.h"
#import "AudioMetadata.h"
#import "PCMGeneratingTask.h"

@interface EncoderTask : NSObject
{
	NSString				*_outputFilename;
	Encoder					*_encoder;
	NSArray					*_tracks;
	AudioMetadata			*_metadata;
	PCMGeneratingTask		*_task;
	BOOL					_writeSettingsToComment;
}

- (id)				initWithTask:(PCMGeneratingTask *)task outputFilename:(NSString *)outputFilename metadata:(AudioMetadata *)metadata;

- (void)			setTracks:(NSArray *)tracks;

- (void)			run:(id) object;
- (void)			stop;
- (void)			removeOutputFile;

- (void)			writeTags;

- (NSString *)		getType;

@end
