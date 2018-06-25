using ProtoSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace crucis
{
    [Desc("消息行为类型")]
    public enum MessageType
    {
        [Desc("调用")]
        Call = 1,
        [Desc("返回")]
        Reply = 2,
        [Desc("异常")]
        Exception = 3,
        [Desc("单路")]
        Oneway = 4
    }

    public class RpcRequestData
    {
        [Index(1)]
        [Label(LabelType.Required)]
        [Desc("服务类型id号")]
        public PSUInt32 ServiceId;

        [Index(2)]
        [Label(LabelType.Required)]
        [Desc("函数的id号")]
        public PSUInt32 Function;

        [Index(3)]
        [Label(LabelType.Required)]
        public MessageType Type;

        [Index(4)]
        [Label(LabelType.Required)]
        public PSUInt32 SeqID;

        [Index(5)]
        [Label(LabelType.Required)]
        [Desc("服务实例id号")]
        public PSUInt64 ServiceObject;

        [Index(6)]
        [Label(LabelType.Required)]
        public PSBinary Content;
    }

    public class RpcResponseData
    {
        [Index(1)]
        [Label(LabelType.Required)]
        public MessageType Type;

        [Index(2)]
        [Label(LabelType.Required)]
        public PSUInt32 SeqID;

        [Index(3)]
        [Label(LabelType.Required)]
        [Desc("服务实例id号")]
        public PSUInt64 ServiceObject;

        [Index(4)]
        [Label(LabelType.Required)]
        public PSBinary Content;
    }
}
