[Mesh]
    [gmg]
        type = CartesianMeshGenerator
        ix = '10 10'
        dim = 2
        iy = 10
        dx = '1 1'
        dy = 1
        show_info = true
        subdomain_id = '0 1'
    []
[]

[Variables]
    [v]
    []
[]



[Kernels]
    [diffusion]
      type = MyDiffusion
      variable = v
    []
    # [time]
    #     type = TimeDerivative
    #     variable = v
    # []
[]

[Executioner]
    type = Steady
    dt = 1
    end_time = 10
    line_search = none
    # petsc_options = 'pc_svd_monitor'
    # petsc_options_iname = '-pc_type -pc_factor_shift'
    # petsc_options_value = 'lu NONZERO'
    petsc_options_iname = '-pc_type'
    petsc_options_value = 'hypre'
    automatic_scaling = 'true'

    nl_abs_tol = 1e-10
    nl_rel_tol = 1e-08

    solve_type = NEWTON
[]


[BCs]
    [left]
        type = DirichletBC
        boundary = left
        variable = v
        value = 300
    []
    [right]
        type = DirichletBC
        boundary = right
        variable = v
        value = 400
    []
[]

[Outputs]
    exodus = true
    [exo]
        type = Exodus
    []
[]