/* -*- Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil -*- */
/*
 * Copyright (c) 2012-2017 University of California, Los Angeles
 *
 * This file is part of ChronoSync, synchronization library for distributed realtime
 * applications for NDN.
 *
 * ChronoSync is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * ChronoSync is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * ChronoSync, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Zhenkai Zhu <http://irl.cs.ucla.edu/~zhenkai/>
 * @author Chaoyi Bian <bcy@pku.edu.cn>
 * @author Alexander Afanasyev <http://lasr.cs.ucla.edu/afanasyev/index.html>
 */

#ifndef CHRONOSYNC_LOGGER_HPP
#define CHRONOSYNC_LOGGER_HPP

#ifdef HAVE_LOG4CXX

#include <log4cxx/logger.h>

#define INIT_LOGGER(name) \
  static log4cxx::LoggerPtr staticModuleLogger = log4cxx::Logger::getLogger(name)

#define _LOG_DEBUG(x) \
  LOG4CXX_DEBUG(staticModuleLogger, x)

#define _LOG_TRACE(x) \
  LOG4CXX_TRACE(staticModuleLogger, x)

#define _LOG_FUNCTION(x) \
  LOG4CXX_TRACE(staticModuleLogger, __FUNCTION__ << "(" << x << ")")

#define _LOG_FUNCTION_NOARGS \
  LOG4CXX_TRACE(staticModuleLogger, __FUNCTION__ << "()")

#define _LOG_ERROR(x) \
  LOG4CXX_ERROR(staticModuleLogger, x)

#else // HAVE_LOG4CXX

#define INIT_LOGGER(name)    struct chronosync__allow_trailing_semicolon
#define _LOG_FUNCTION(x)     struct chronosync__allow_trailing_semicolon
#define _LOG_FUNCTION_NOARGS struct chronosync__allow_trailing_semicolon
#define _LOG_TRACE(x)        struct chronosync__allow_trailing_semicolon
#define INIT_LOGGERS(x)      struct chronosync__allow_trailing_semicolon
#define _LOG_ERROR(x)        struct chronosync__allow_trailing_semicolon

#ifdef _DEBUG

#include <thread>
#include <iostream>
#include <ndn-cxx/util/time.hpp>

#define _LOG_DEBUG(x) \
  std::clog << ndn::time::system_clock::now() << " " << std::this_thread::get_id() << \
               " " << x << std::endl

#else // _DEBUG

#define _LOG_DEBUG(x) struct chronosync__allow_trailing_semicolon

#endif // _DEBUG

#endif // HAVE_LOG4CXX

#endif // CHRONOSYNC_LOGGER_HPP
