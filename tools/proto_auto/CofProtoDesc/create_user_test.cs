using ProtoSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace crucis
{
    [Desc("错误码")]
    public enum ErrorCode
    {
        [Desc("成功")]
        OK = 1,
        [Desc("位置被占用")]
        PLACEHOLDER = 2,
        [Desc("不存在")]
        NOT_EXIST = 3
    }

    [Desc("返回结果")]
    public class AddUserRes
    {
        [Index(1)]
        [Label(LabelType.Required)]
        [Desc("card_id")]
        public PSString CardId;

        [Index(2)]
        [Label(LabelType.Required)]
        [Desc("错误码")]
        public ErrorCode Code;

    }

    [Index(1)]
    [ImitateSingleton]
    interface create_user_test
    {
        [Index(1)]
        [Desc("创建用户例子")]
        AddUserRes AddUser(PSUInt64 uid, PSString nick_name, PSUInt32 seq_id, PSBoolean online);
    }
}
