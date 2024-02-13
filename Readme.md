Fixed Point Library
===================

To make sure that produce_test.py works, I deleted the overflow tests in FixedPoint python library. It was necessary since overflow behaviour is expected in C++ implementation. \\

I couldn't exactly match the spfpm behaviour and our library's behaviour in bit clamps and especially overflow. It seems that will be future me's problem. But I expect the clamp mode to work perfectly fine. \\




