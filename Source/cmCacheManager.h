/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) 2000 National Library of Medicine
  All rights reserved.

  See COPYRIGHT.txt for copyright details.

=========================================================================*/
#ifndef cmCacheManager_h
#define cmCacheManager_h

#include "cmStandardIncludes.h"
class cmMakefile;

/** \class cmCacheManager
 * \brief Control class for cmake's cache
 *
 * Load and Save CMake cache files.
 * 
 */
class cmCacheManager
{
public:
  /**
   * Types for the cache entries.  These are useful as
   * hints for a cache editor program.  Path should bring
   * up a file chooser, BOOL a check box, and STRING a 
   * text entry box, FILEPATH is a full path to a file which
   * can be different than just a path input
   */
  enum CacheEntryType{ BOOL=0, PATH, FILEPATH, STRING  };
  static CacheEntryType StringToType(const char*);
  //! Singleton pattern get instance of the cmCacheManager.
  static cmCacheManager* GetInstance();

  //! Load a cache for given makefile.  Loads from ouput home.
  bool LoadCache(cmMakefile*);
  
  //! Save cache for given makefile.  Saves to ouput home CMakeCache.txt
  bool SaveCache(cmMakefile*);
  
  //! Add an entry into the cache
  void AddCacheEntry(const char* key, const char* value, CacheEntryType type);
  
  //! Get a value from the cache given a key
  const char* GetCacheValue(const char* key);
  
private:
  static cmCacheManager* s_Instance;
  class CacheEntry
  {
  public:
    std::string m_Value;
    CacheEntryType m_Type;
  };
  std::map<std::string, CacheEntry> m_Cache;
};

#endif
