using UnrealBuildTool;

public class TestingExamples_Specs : ModuleRules
{
    public TestingExamples_Specs(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
            }
        );

       
        PrivateDependencyModuleNames.AddRange(
            new []
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore", 
                
                // For Mocking
                "GoogleTest",
                
                // Modules under test 
                "TestingExamples"
            }
        );
        
        PublicDefinitions.AddRange(new []
        {
		    // OS MACROS
            "GTEST_OS_WINDOWS=1",
            "GTEST_OS_WINDOWS_MOBILE=0",
            "GTEST_OS_LINUX_ANDROID=0",
            "GTEST_OS_LINUX=0",
            "GTEST_OS_MAC=0",
            "GTEST_OS_HPUX=0",
            "GTEST_OS_QNX=0",
            "GTEST_OS_FREEBSD=0",
            "GTEST_OS_NACL=0",
            "GTEST_OS_NETBSD=0",
            "GTEST_OS_FUCHSIA=0",
            "GTEST_OS_LINUX_ANDROID=0",
            "GTEST_OS_SYMBIAN=0",
            "GTEST_OS_WINDOWS_MINGW=0",
            "GTEST_OS_WINDOWS_PHONE=0",
            "GTEST_OS_WINDOWS_RT=0",
            "GTEST_OS_CYGWIN=0",
            "GTEST_OS_SOLARIS=0",
            "GTEST_OS_WINDOWS_TV_TITLE=0",
            "GTEST_OS_IOS=0",
            "GTEST_OS_AIX=0",
            "GTEST_OS_ZOS=0",
       
            // Define Macros
            "GTEST_DONT_DEFINE_FAIL=0",
            "GTEST_DONT_DEFINE_SUCCEED=0",
            "GTEST_DONT_DEFINE_ASSERT_EQ=0",
            "GTEST_DONT_DEFINE_ASSERT_NE=0",
            "GTEST_DONT_DEFINE_ASSERT_LE=0",
            "GTEST_DONT_DEFINE_ASSERT_LT=0",
            "GTEST_DONT_DEFINE_ASSERT_GE=0",
            "GTEST_DONT_DEFINE_ASSERT_GT=0",
            "GTEST_DONT_DEFINE_TEST=0",

            "GTEST_HAS_DOWNCAST_=0",
            "GTEST_HAS_MUTEX_AND_THREAD_LOCAL_=0",
            "GTEST_HAS_NOTIFICATION_=0",
            "GTEST_HAS_ABSL=0",
            "GTEST_HAS_GETTIMEOFDAY_=0",

            "__GXX_EXPERIMENTAL_CXX0X__=0",
            "GTEST_USES_PCRE=0",
            "GTEST_USES_POSIX_RE=0",
            "GTEST_ENV_HAS_TR1_TUPLE_=0",
            "GTEST_LINKED_AS_SHARED_LIBRARY=0",
            "GTEST_CREATE_SHARED_LIBRARY=0",
            "GTEST_CAN_STREAM_RESULTS_=0",
            "GTEST_FOR_GOOGLE_=0",
            "GTEST_GCC_VER_=0",
            
            "GTEST_INTERNAL_HAS_STRING_VIEW=0",
            "GTEST_OS_DRAGONFLY=0",
            "GTEST_OS_GNU_KFREEBSD=0",
            "GTEST_OS_OPENBSD=0",
            "GTEST_OS_HAIKU=0",
            "GTEST_OS_ESP8266=0",
            "GTEST_OS_ESP32=0",

            "WIN32_LEAN_AND_MEAN=1"
        });
    }
}