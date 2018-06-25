using ProtoSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace crucis
{
    [Index(1)]
    [ImitateSingleton]
    interface echo_test
    {
        [Index(1)]
        [Desc("示范")]
        PSString Echo(PSString text,PSInt32 times);
    }
}
