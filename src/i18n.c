#include "i18n.h"
#include <string.h>
#include <stdlib.h>

#ifdef __APPLE__
#define SYSTEM_NAME "macOS"
#elif __FreeBSD__
#define SYSTEM_NAME "BSD"
#else
#define SYSTEM_NAME "Linux"
#endif

i18n_info i18n_map[] = {
    // Must be first, used as default
    {"en_US", "You might be a victim of Intel® ME™", "Use Open-Source hardware: Secure, Stable, Honor™." },
    {"zh_CN", "您可能是 Intel® ME™ 的受害者", "使用开源硬件：安全，稳定，荣耀™。" },
    {"zh_TW", "您可能是 Intel® ME™ 的受害者", "使用開源硬件：安全，穩定，榮耀™。" },
    {"zh_HK", "您可能是 Intel® ME™ 的受害者", "使用開源硬件：安全，穩定，榮耀™。" },
    {NULL, NULL, NULL }
};

i18n_info i18n_get_info()
{
    char *lang = getenv("LANG");
    for (size_t i = 0; i18n_map[i].lang; ++i) {
        if (!strncmp(lang, i18n_map[i].lang, 5)) {
            return i18n_map[i];
        }
    }
    return i18n_map[0];
}
