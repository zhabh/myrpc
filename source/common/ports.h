#ifndef _CRUCIS_PORTS_H_
#define _CRUCIS_PORTS_H_
#include <common.h>
#include <string>

namespace crucis {

// ∏Ò Ω crucis_tcp:/127.0.0.1:80/service_type/id

class ports
{
public:
	explicit ports(const std::string& inPut) {
		m_bIsInitial = Parse(inPut) == 0;
	}

	explicit ports(const std::string& sProtocalType, const std::string& sIpAddress, unsigned short uPort, int iServerType, long seqID) {
		
		if (sProtocalType.length() < 1 || sIpAddress.length() < 1 || uPort < 1 || seqID < 1) {
			m_bIsInitial = false;
		}
		else {
			m_sProtocalType = sProtocalType;
			m_sIpAddress = sIpAddress;
			m_uPort = uPort;
			m_eServerType = (eServerType)iServerType;
			m_SequenceId = seqID;
			m_bIsInitial = true;
		}

	}

	virtual ~ports(){}

	bool Is_Initial() {
		return m_bIsInitial;
	}

	std::string GetProtocalType() {
		return m_sProtocalType;
	}

	std::string GetIpAddress() {
		return m_sIpAddress;
	}
	
	unsigned short GetuPort() {
		return m_uPort;
	}

	eServerType GetServerType() {
		return m_eServerType;
	}

	long GetSequenceId() {
		return m_SequenceId;
	}


private:
	int Parse(const std::string& str) {
		if (str.length() < 1) {
			return 1;
		}

		std::string::size_type pos = str.find('/');
		if (pos == std::string::npos) {
			return 1;
		}

		m_sProtocalType = str.substr(0, pos);
		//...

		return 0;
	}
private:
	bool m_bIsInitial;
	std::string m_sProtocalType;
	std::string m_sIpAddress;
	unsigned short m_uPort;
	eServerType m_eServerType;
	long m_SequenceId;
};

} // namespace crucis

#endif // _CRUCIS_PORTS_H_