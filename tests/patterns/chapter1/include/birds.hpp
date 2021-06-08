#pragma once

#ifndef BIRDS_HPP
#define BIRDS_HPP

class Bird {};

class FlyingBird : public Bird {
protected:
  double speed;
  double direction;

public:
  FlyingBird(double speed, double direction)
      : speed(speed), direction(direction) {}
  virtual ~FlyingBird() {}
  virtual void fly() = 0;
};

class Eagle : public FlyingBird {
public:
  Eagle(double speed, double direction) : FlyingBird(speed, direction) {}
  void fly() override;
};

class Vulture : public FlyingBird {
public:
  Vulture(double speed, double direction) : FlyingBird(speed, direction) {}
  void fly() override;
};

#endif
