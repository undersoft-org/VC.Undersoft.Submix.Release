/*
 * submix.cpp
 *
 *  Created on: 31 mar 2021
 *  Author: Darius Hanc
 */
#include "submix.h"

uint32_t SubmixMap32(const uint32_t src, const uint32_t dest)
{
	uint32_t subsrc,
		sumsub = 0,
		_src = src;

	int msbid = (int)ReverseIndex32(dest);
	uint32_t bitmask = 0xFFFFFFFF >> (31 - msbid);
	
	for (; ;)
	{
		subsrc = (_src & bitmask);

		if (subsrc > dest)
			subsrc -= dest;

		sumsub += subsrc;

		if (sumsub > dest)
			sumsub -= dest;

		_src >>= msbid;

		if (_src == 0)
			return sumsub;
	}
}

uint32_t SubmixMapToMask32(const uint32_t src, const uint32_t dest, const uint32_t bitmask, const int32_t msbid)
{
	uint32_t subsrc,
		sumsub = 0,
		_src = src;

	for (; ;)
	{
		subsrc = (_src & bitmask);

		if (subsrc > dest)
			subsrc -= dest;

		sumsub += subsrc;

		if (sumsub > dest)
			sumsub -= dest;

		_src >>= msbid;

		if (_src == 0)
			return sumsub;
	}
}

uint32_t SubmixMask32(const uint32_t dest)
{
	int msbid = (int)ReverseIndex32(dest);
	return  0xFFFFFFFF >> (31 - msbid);
}

int32_t	SubmixMsbId32(const uint32_t dest)
{
	return (int)ReverseIndex32(dest);
}

uint64_t SubmixMap64(const uint64_t src, const uint64_t dest)
{
	int msbid = (int)ReverseIndex64(dest);
	uint64_t bitmask = 0xFFFFFFFFFFFFFFFF >> (63 - msbid);
	uint64_t subsrc, sumsub = 0, _src = src;

	for (; ; )
	{
		subsrc = (_src & bitmask);

		if (subsrc > dest)
			subsrc -= dest;

		sumsub += subsrc;

		if (sumsub > dest)
			sumsub -= dest;

		_src >>= msbid;

		if (_src == 0)
			return sumsub;
	}
}

uint64_t SubmixMapToMask64(const uint64_t src, const uint64_t dest, const uint64_t bitmask, const int32_t msbid)
{
	uint64_t subsrc, sumsub = 0, _src = src;

	for (; ; )
	{
		subsrc = (_src & bitmask);

		if (subsrc > dest)
			subsrc -= dest;

		sumsub += subsrc;

		if (sumsub > dest)
			sumsub -= dest;

		_src >>= msbid;

		if (_src == 0)
			return sumsub;
	}
}

uint64_t SubmixMask64(const uint64_t dest)
{
	int msbId = (int)ReverseIndex64(dest);
	return 0xFFFFFFFFFFFFFFFF >> (63 - msbId);
}

int32_t SubmixMsbId64(const uint64_t dest)
{
	return (int)ReverseIndex64(dest);
}