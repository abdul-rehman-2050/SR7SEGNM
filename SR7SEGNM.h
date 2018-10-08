/*


  ---------------------------------------------------------------------
  @Developer
  	1-Abdul Rehman
	------------------------------------------------------------------

 @license
|| | This library is free software; you can redistribute it and/or
|| | modify it under the terms of the GNU Lesser General Public
|| | License as published by the Free Software Foundation; version
|| | 2.1 of the License.
|| |
|| | This library is distributed in the hope that it will be useful,
|| | but WITHOUT ANY WARRANTY; without even the implied warranty of
|| | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
|| | Lesser General Public License for more details.
|| |
|| | You should have received a copy of the GNU Lesser General Public
|| | License along with this library; if not, write to the Free Software
|| | Strange Lab., Abbot road shimla pahari, Lahore,Pakistan
|| 
|| 
||

*/


#ifndef SR7SEGNM_H_
#define SR7SEGNM_H_


#include <Arduino.h>

class SR7SEGNM{
public:
	// methods
	SR7SEGNM(int clockPin,int dataPin,int StrobPin,int nSegments);
	void begin();/*will initialize pins and reset display*/
	void offAllSegments();	/*Off all segments*/
	void reset(); /*Put zero on all segments*/
	void updateSegments(int segmentBuffer[]);

private:
	// members
	char numberOfSegments;
	int clockPin;
	int dataPin;
	int strobPin;
	//enum { arrsize = 11 };
	/*
		segChar array are seven segments codes 
		0-for off 
		1-for on	[common cathod like or use with uln2003 etc]
		
	*/
	 static const byte segChar[11];

};

#endif


