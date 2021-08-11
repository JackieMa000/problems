#ifndef DSA_SRC_DSA_CONFIG_H_
#define DSA_SRC_DSA_CONFIG_H_

namespace dsa {

#if __has_attribute(internal_linkage)
#  define INTERN __attribute__ ((internal_linkage))
#else
#  define INTERN static
#endif

#if __has_attribute(warn_unused_result)
#  define NODISCARD __attribute__((warn_unused_result))
#else
#  define NODISCARD [[nodiscard]]
#endif

#if __has_attribute(unused)
#   define UNUSED __attribute__((unused))
#else
#   define UNUSED [[maybe_unused]]
#endif

#define CONSTEXPR constexpr

#define HIDDEN __attribute__ ((__visibility__("hidden")))

#define DELETE_FUNCTION = delete

#define TEMPLATE_VIS __attribute__ ((__visibility__("default")))

//Project root namespace
#define DSA dsa

// Test Flag
#define DSA_TEST

}
#endif //DSA_SRC_DSA_CONFIG_H_
