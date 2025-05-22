
#pragma once

/**
 * @brief Interface for application operation modes.
 * 
 * This abstract class defines a common interface for different modes of the
 * application (e.g., entry counting, word counting, checksum calculation, help display).
 * 
 * All derived classes must implement the exec() method to perform their
 * specific behavior.
 */
class IMode {
public:
    /**
     * @brief Virtual destructor.
     * 
     * Ensures proper cleanup of derived classes when deleted via a base pointer.
     */
    virtual ~IMode() = default;

    /**
     * @brief Executes the mode's main logic.
     * 
     * This pure virtual function must be implemented by all subclasses
     * to define the specific behavior of the mode.
     */
    virtual void exec() = 0;
};
