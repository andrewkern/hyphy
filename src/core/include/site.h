/*

HyPhy - Hypothesis Testing Using Phylogenies.

Copyright (C) 1997-now
Core Developers:
   Sergei L Kosakovsky Pond (sergeilkp@icloud.com)
   Art FY Poon    (apoon42@uwo.ca)
   Steven Weaver (sweaver@temple.edu)

Module Developers:
        Lance Hepler (nlhepler@gmail.com)
        Martin Smith (martin.audacis@gmail.com)

Significant contributions from:
  Spencer V Muse (muse@stat.ncsu.edu)
  Simon DW Frost (sdf22@cam.ac.uk)

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef _GENSITE_
#define _GENSITE_
//#pragma once

#include "avllist.h"
#include "avllistx.h"
#include "avllistxl.h"
#include "list.h"
#include "parser.h"
#include "simplelist.h"
#include "stdlib.h"
#include "translation_table.h"


// data set file state data struct
struct FileState {

  _TranslationTable *translationTable;
  long curSpecies, totalSpeciesRead, totalSitesRead, totalSpeciesExpected,
       totalSitesExpected, curSite, maxStringLength, pInSrc, currentFileLine;
  bool acceptingCommands, allSpeciesDefined, interleaved, autoDetect,
       isSkippingInNEXUS;
  int fileType, baseLength;
  char repeat, skip;

  _String *theSource, *theNamespace;

  _SimpleList rawLinesFormat;

};
//_________________________________________________________

class _Site : public _StringBuffer {

public:

  // does nothing
  _Site(void);

  // length allocation
  _Site(unsigned long length, long ref_no);

  // data constructor
  _Site(_String const &);

  // data constructor
  _Site(char);

  // reference constructor
  _Site(long);

  // destructor
  virtual ~_Site(void);

  void Complete(void);

  long GetRefNo     (void) const { return refNo < 0L ? -refNo - 2L : refNo - 2L; }
  bool IsComplete   (void) const    { return refNo < 0L; }
  void SetRefNo     (long r) { refNo = -r - 2L; }
    
  void *      operator new       (size_t size);
  void        operator delete    (void * p);


private:
  long refNo; // if this site contains a reference to another one
  // if refNo is negative, then shows whether the definition of this datatype
  // has been completed
};

#endif
