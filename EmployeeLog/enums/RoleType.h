#pragma once

#include <cassert>

enum class RoleType {
    DEVELOPER,
    QUALITY_ASSURANCE,
    DEVOPS
};

char* getRoleType(RoleType roleType) {
    switch (roleType) {
        case RoleType::DEVELOPER: return "Developer";
        case RoleType::QUALITY_ASSURANCE: return "QA";
        case RoleType::DEVOPS: return "DevOps";
        default: assert(false);
    }
}