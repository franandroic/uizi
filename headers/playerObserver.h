#pragma once

class PlayerObserver {

public:

    virtual void updatePlayerListener() = 0;

    virtual ~PlayerObserver() = default;
};