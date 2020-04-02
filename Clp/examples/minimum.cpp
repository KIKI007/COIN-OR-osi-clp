/* $Id$ */
// Copyright (C) 2002, International Business Machines
// Corporation and others.  All Rights Reserved.
// This code is licensed under the terms of the Eclipse Public License (EPL).

#include "ClpSimplex.hpp"
int main(int argc, const char *argv[])
{
     ClpSimplex  model;
     int status;
     if (argc < 2) {


         try {
             status = model.readMps("p0033.mps", true);
         } catch (const std::exception& e) {
             fprintf(stderr, "No file p0033.mps found.\n");
             exit(1);
         }

     } else
          status = model.readMps(argv[1]);
     if (!status) {
          model.primal();
     }
     return 0;
}
