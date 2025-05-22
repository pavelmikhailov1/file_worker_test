
#pragma once

#include "IMode.hpp"

/**
 * @brief Mode that displays help information for the application.
 * 
 * This class implements the IMode interface and provides a textual
 * description of the command-line arguments supported by the application.
 * It is typically invoked when the user passes the `-h` or `--help` flag.
 */
class HelpMode final : public IMode {
public:
    /**
     * @brief Executes the help mode.
     * 
     * Prints detailed usage instructions, including available command-line
     * options, their descriptions, and supported operation modes.
     */
    void exec() override;
};
